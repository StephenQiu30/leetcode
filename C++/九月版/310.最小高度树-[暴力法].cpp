/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 0)
        {
            return {};
        }
        if (n == 1)
        {
            return {0};
        }
        vector<vector<int>> adj(n);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int bestHeight = INT_MAX;
        vector<int> res;
        for (int root = 0; root < n; root++)
        {
            vector<int> dist(n, -1);
            queue<int> q;
            q.push(root);
            dist[root] = 0;
            int maxd = 0;
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v : adj[u])
                {
                    if (dist[v] == -1)
                    {
                        dist[v] = dist[u] + 1;
                        maxd = max(maxd, dist[v]);
                        q.push(v);
                    }
                }
            }
            if (maxd < bestHeight)
            {
                bestHeight = maxd;
                res.clear();
                res.push_back(root);
            }
            else if (maxd == bestHeight)
            {
                res.push_back(root);
            }
        }
        return res;
    }
};
// @lc code=end
