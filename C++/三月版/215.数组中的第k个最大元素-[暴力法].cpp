/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // 先对数组进行降序排序
        sort(nums.rbegin(), nums.rend());
        return nums[k - 1];
    }
};
// @lc code=end
