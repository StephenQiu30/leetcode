/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接 [BFS]
 */

// @lc code=start
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1];
            vector<char> visited(n + 1, 0);
            if (hasPathDFS(u, v, adj, visited))
            {
                return e;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }

private:
    bool hasPathDFS(int src, int target, vector<vector<int>> &adj, vector<char> &visited)
    {
        if (src == target)
        {
            return true;
        }
        visited[src] = 1;
        for (int nei : adj[src])
        {
            if (!visited[nei])
            {
                if (hasPathDFS(nei, target, adj, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
