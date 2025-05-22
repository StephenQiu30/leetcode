/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍 [递归]
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        return robFrom(0, nums);
    }
    int robFrom(int i, vector<int> &nums)
    {
        if (i >= nums.size())
        {
            return 0;
        }
        return max(robFrom(i + 1, nums), nums[i] + robFrom(i + 2, nums));
    }
};
// @lc code=end
