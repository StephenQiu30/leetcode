/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> memo(nums.size(), -1);
        return robFrom(0, nums, memo);
    }
    int robFrom(int i, vector<int> &nums, vector<int> &memo)
    {
        if (i >= nums.size())
        {
            return 0;
        }
        if (memo[i] != -1)
        {
            return memo[i];
        }
        memo[i] = max(robFrom(i + 1, nums, memo), nums[i] + robFrom(i + 2, nums, memo));
        return memo[i];
    }
};
// @lc code=end
