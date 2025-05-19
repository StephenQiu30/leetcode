/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int maxVal = nums[0];
        int minVal = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int tempMax = maxVal;
            maxVal = max({nums[i], nums[i] * maxVal, nums[i] * minVal});
            minVal = min({nums[i], nums[i] * tempMax, nums[i] * minVal});
            result = max(result, maxVal);
        }
        return result;
    }
};
// @lc code=end
