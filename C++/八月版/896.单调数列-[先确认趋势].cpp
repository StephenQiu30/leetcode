/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列 [先确认趋势]
 */

// @lc code=start
class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        int n = (int)nums.size();
        int i = 1;
        while (i < n && nums[i] == nums[i - 1])
        {
            // 跳过相等
            ++i;
        }
        // 全部相等
        if (i == n)
        {
            return true;
        }
        // 确定趋势
        bool increase = nums[i] > nums[i - 1];
        for (; i < n; i++)
        {
            if (increase && nums[i] < nums[i - 1])
            {
                return false;
            }
            if (!increase && nums[i] > nums[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
