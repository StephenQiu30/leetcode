/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数 [动态规划]
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
        int a = 0, b = 1;
        for (int i = 2; i <= n; i++)
        {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
// @lc code=end
