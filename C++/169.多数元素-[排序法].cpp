/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素 [排序法]
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
// @lc code=end
