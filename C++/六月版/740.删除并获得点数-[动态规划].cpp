/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int maxValue = *max_element(nums.begin(), nums.end());
        vector<int> sum(maxValue + 1, 0);
        for (int num : nums)
        {
            sum[num] += num;
        }
        vector<int> dp(maxValue + 1, 0);
        dp[0] = 0;
        dp[1] = sum[1];
        for (int i = 2; i <= maxValue; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + sum[i]);
        }
        return dp[maxValue];
    }
};
// @lc code=end
