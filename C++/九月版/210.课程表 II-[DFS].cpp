/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II [DFS]
 */

// @lc code=start
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        g.assign(numCourses, {});
        for (auto &p : prerequisites)
        {
            g[p[1]].push_back(p[0]);
        }
        visited.assign(numCourses, 0);
        order.clear();
        hasCycle = false;
        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i);
            }
            if (hasCycle)
            {
                return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }

private:
    vector<vector<int>> g;
    vector<int> visited;
    vector<int> order;
    bool hasCycle = false;

    void dfs(int u)
    {
        if (hasCycle)
        {
            return;
        }
        visited[u] = 1;
        for (int v : g[u])
        {
            if (visited[v] == 0)
            {
                dfs(v);
                if (hasCycle)
                {
                    return;
                }
            }
            else if (visited[v] == 1)
            {
                // 回边，存在环
                hasCycle = true;
                return;
            }
        }
        visited[u] = 2;
        // 后序
        order.push_back(u);
    }
};
// @lc code=end
