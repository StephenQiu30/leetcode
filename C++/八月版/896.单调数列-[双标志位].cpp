/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列 [双标志位]
 */

// @lc code=start
class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        bool inc = true, dec = true;
        for (int i = 1; i < (int)nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                dec = false;
            }
            if (nums[i] < nums[i - 1])
            {
                inc = false;
            }
            if (!inc && !dec)
            {
                // 提前退出
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
