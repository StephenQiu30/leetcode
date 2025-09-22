/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }
        for (int i = 0; i < n; i++)
        {
            bool leftOK = (i == 0) || (nums[i] > nums[i - 1]);
            bool rightOK = (i == n - 1) || (nums[i] > nums[i + 1]);
            if (leftOK && rightOK)
            {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end
