/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量 [BFS]
 */

// @lc code=start
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count++;
                q.push(i);
                visited[i] = true;
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    for (int v = 0; v < n; v++)
                    {
                        if (isConnected[u][v] == 1 && !visited[v])
                        {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
        }
        return count;
    }
};
// @lc code=end
