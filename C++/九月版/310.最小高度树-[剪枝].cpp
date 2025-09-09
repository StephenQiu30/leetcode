/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树 [剪枝]
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
        vector<int> degree(n, 0);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 1)
            {
                q.push(i);
            }
        }
        int remaining = n;
        while (remaining > 2)
        {
            int size = q.size();
            remaining -= size;
            for (int i = 0; i < size; i++)
            {
                int leaf = q.front();
                q.pop();
                for (int nei : adj[leaf])
                {
                    if (--degree[nei] == 1)
                    {
                        q.push(nei);
                    }
                }
            }
        }
        vector<int> res;
        while (!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
// @lc code=end
