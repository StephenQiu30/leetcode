/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};
// @lc code=end
