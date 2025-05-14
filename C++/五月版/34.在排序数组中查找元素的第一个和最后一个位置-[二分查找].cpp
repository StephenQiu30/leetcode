/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置 [二分查找]
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = findFirst(nums, target);
        int right = findLast(nums, target);
        return {left, right};
    }

private:
    int findFirst(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1, ans = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] >= target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            if (nums[mid] == target)
            {
                ans = mid;
            }
        }
        return ans;
    }
    int findLast(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1, ans = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] <= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
            if (nums[mid] == target)
            {
                ans = mid;
            }
        }
        return ans;
    }
};
// @lc code=end
