/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(3, 0));
        // 第一天持股
        dp[0][0] = -prices[0];
        // 卖出
        dp[0][1] = 0;
        // 休息
        dp[0][2] = 0;
        for (int i = 1; i < n; i++)
        {

            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }
        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};
// @lc code=end
