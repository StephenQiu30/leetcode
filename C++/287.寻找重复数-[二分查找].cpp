/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数 [二分查找]
 */

// @lc code=start
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int left = 1, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int count = 0;
            for (int num : nums)
            {
                if (num <= mid)
                {
                    count++;
                }
            }
            if (count > mid)
            {
                // 重复数在 [left, mid]
                right = mid;
            }
            else
            {
                // 重复数在 [mid+1, right]
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end
