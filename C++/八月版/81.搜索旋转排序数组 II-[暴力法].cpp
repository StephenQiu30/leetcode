/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II [暴力法]
 */

// @lc code=start
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        for (int num : nums)
        {
            if (num == target)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
