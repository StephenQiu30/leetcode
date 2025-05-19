/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组 [前缀]
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int result = nums[0];
        int prod = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            prod *= nums[i];
            result = max(result, prod);
            if (prod == 0)
            {
                prod = 1;
            }
        }
        prod = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            prod *= nums[i];
            result = max(result, prod);
            if (prod == 0)
            {
                prod = 1;
            }
        }
        return result;
    }
};
// @lc code=end
