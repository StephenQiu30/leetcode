/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量 [DFS]
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
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ++count;
                dfs(isConnected, visited, i);
            }
        }
        return count;
    }
    void dfs(vector<vector<int>> &isConnected, vector<bool> &visited, int i)
    {
        visited[i] = true;
        for (int j = 0; j < isConnected.size(); j++)
        {
            if (isConnected[i][j] == 1 && !visited[j])
            {
                dfs(isConnected, visited, j);
            }
        }
    }
};
// @lc code=end
