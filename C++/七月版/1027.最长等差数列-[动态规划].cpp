/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
        {
            return n;
        }
        vector<unordered_map<int, int>> dp(n);
        int res = 2;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int d = nums[i] - nums[j];
                dp[i][d] = dp[j].count(d) ? dp[j][d] + 1 : 2;
                res = max(res, dp[i][d]);
            }
        }
        return res;
    }
};
// @lc code=end
