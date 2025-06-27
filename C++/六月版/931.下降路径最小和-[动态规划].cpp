/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int minPrev = dp[i - 1][j];
                if (j > 0)
                {
                    minPrev = min(minPrev, dp[i - 1][j - 1]);
                }
                if (j < n - 1)
                {
                    minPrev = min(minPrev, dp[i - 1][j + 1]);
                }
                dp[i][j] = matrix[i][j] + minPrev;
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
// @lc code=end
