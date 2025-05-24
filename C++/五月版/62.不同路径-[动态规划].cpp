/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // 初始化第一行都是1
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                // 当前 = 上一个 + 左边
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end
