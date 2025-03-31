/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置 [常规方法]
 */

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // 获取当前数组的长度
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= target)
            {
                return i;
            }
        }

        return n;
    }
};
// @lc code=end
