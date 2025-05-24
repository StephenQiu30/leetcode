/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径 [DFS]
 */

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> memo(m, vector<int>(n, 0));
        return dfs(m - 1, n - 1, memo);
    }

private:
    int dfs(int i, int j, vector<vector<int>> &memo)
    {
        if (i == 0 || j == 0)
        {
            return 1;
        }
        if (memo[i][j] != 0)
        {
            return memo[i][j];
        }
        memo[i][j] = dfs(i - 1, j, memo) + dfs(i, j - 1, memo);
        return memo[i][j];
    }
};
// @lc code=end
