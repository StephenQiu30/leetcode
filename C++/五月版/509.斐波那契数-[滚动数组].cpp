/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数 [滚动数组]
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
        int prev2 = 0;
        int prev1 = 1;
        int current;
        for (int i = 2; i <= n; i++)
        {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
};
// @lc code=end
