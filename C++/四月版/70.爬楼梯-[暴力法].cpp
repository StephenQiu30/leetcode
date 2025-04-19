/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
// @lc code=end
