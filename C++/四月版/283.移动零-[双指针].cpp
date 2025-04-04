/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零 [双指针]
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int zeroIndex = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                swap(nums[zeroIndex++], nums[i]);
            }
        }
    }
};
// @lc code=end
