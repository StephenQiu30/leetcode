/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组 [二分查找]
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            // 判断左半边是否有序
            if (nums[left] <= nums[mid])
            {
                // target 在左边
                if (nums[left] <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    // target 在右边
                    left = mid + 1;
                }
            }
            else
            {
                // 右半边有序
                if (nums[mid] < target && target <= nums[right])
                {
                    // target 在右边
                    left = mid + 1;
                }
                else
                {
                    // target 在左边
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
