/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        long long curMax = 0, maxSum = LLONG_MIN;
        for (long long num : nums)
        {
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);
        }
        return static_cast<int>(maxSum);
    }
};
// @lc code=end
