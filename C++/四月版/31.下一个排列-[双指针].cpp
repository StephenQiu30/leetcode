/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列 [双指针]
 */

// @lc code=start
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size(), i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }
        if (i >= 0)
        {
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i])
            {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end
