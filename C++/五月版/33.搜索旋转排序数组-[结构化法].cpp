/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组 [结构化法]
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        int rotate = left;

        // 2. 普通二分查找（调整索引）
        left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int realMid = (mid + rotate) % n;

            if (nums[realMid] == target)
            {
                return realMid;
            }
            if (nums[realMid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }
};
// @lc code=end
