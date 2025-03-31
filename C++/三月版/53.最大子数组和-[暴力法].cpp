/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        long long maxSum = LLONG_MIN;

        for (int i = 0; i < n; i++)
        {
            long long sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return static_cast<int>(maxSum);
    }
};
// @lc code=end
