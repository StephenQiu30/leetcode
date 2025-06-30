/*
 * @lc app=leetcode.cn id=2140 lang=cpp
 *
 * [2140] 解决智力问题 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            long long take = questions[i][0];
            int skip = questions[i][1];
            if (i + skip + 1 < n)
            {
                take += dp[i + skip + 1];
            }
            dp[i] = max(take, dp[i + 1]);
        }
        return dp[0];
    }
};
// @lc code=end
