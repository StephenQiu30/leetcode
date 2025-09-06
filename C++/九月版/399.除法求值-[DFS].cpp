/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值 [DFS]
 */

// @lc code=start
class Solution
{
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(const string &current, const string &target, unordered_set<string> visited)
    {
        // 节点不存在
        if (!graph.count(current))
        {
            return -1.0;
        }
        if (current == target)
        {
            return 1.0;
        }
        visited.insert(current);
        for (auto &pair : graph[current])
        {
            const string &neigh = pair.first;
            double w = pair.second;
            if (visited.count(neigh))
            {
                continue;
            }
            double sub = dfs(neigh, target, visited);
            if (sub > 0)
            {
                return w * sub;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        graph.clear();
        int m = equations.size();
        for (int i = 0; i < m; i++)
        {
            string a = equations[i][0], b = equations[i][1];
            double v = values[i];
            graph[a].push_back({b, v});
            graph[b].push_back({a, 1.0 / v});
        }
        vector<double> ans;
        for (auto &q : queries)
        {
            string x = q[0], y = q[1];
            if (!graph.count(x) || !graph.count(y))
            {
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            double res = dfs(x, y, visited);
            ans.push_back(res);
        }
        return ans;
    }
};
// @lc code=end
