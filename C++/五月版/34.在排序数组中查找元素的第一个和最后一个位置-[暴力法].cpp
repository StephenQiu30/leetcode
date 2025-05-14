/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = -1, last = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                if (first == -1)
                {
                    first = i;
                }
                last = i;
            }
        }
        return {first, last};
    }
};
// @lc code=end
