/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int minVal = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < minVal)
            {
                minVal = nums[i];
            }
        }
        return minVal;
    }
};
// @lc code=end
