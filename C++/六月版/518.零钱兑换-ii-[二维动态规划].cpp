/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II [二维动态规划]
 */

// @lc code=start
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<uint64_t>> dp(n + 1, vector<uint64_t>(amount + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            int coin = coins[i - 1];
            for (int j = 0; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= coin)
                {
                    dp[i][j] += dp[i][j - coin];
                }
            }
        }
        return dp[n][amount];
    }
};
// @lc code=end
