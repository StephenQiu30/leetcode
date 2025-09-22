/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值 [二分查找]
 */

// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (right - left) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end
