/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字 [数学方法]
 */

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum_expect = n * (n + 1) / 2;
        int sum_actual = 0;
        for (int num : nums)
        {
            sum_actual += num;
        }
        return sum_expect - sum_actual;
    }
};
// @lc code=end
