/*
 * @lc app=leetcode.cn id=2466 lang=cpp
 *
 * [2466] 统计构造好字符串的方案数 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    const int MOD = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= high; i++)
        {
            if (i >= zero)
            {
                dp[i] = (dp[i] + dp[i - zero]) % MOD;
            }
            if (i >= one)
            {
                dp[i] = (dp[i] + dp[i - one]) % MOD;
            }
        }
        int res = 0;
        for (int i = low; i <= high; i++)
        {
            res = (res + dp[i]) % MOD;
        }
        return res;
    }
};
// @lc code=end
