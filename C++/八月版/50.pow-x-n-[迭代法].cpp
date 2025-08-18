/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n) [暴力法]
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        long long N = n;
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }
        double res = 1.0;
        double base = x;
        while (N > 0)
        {
            if (N & 1)
            {
                res *= base;
            }
            base *= base;
            N >>= 1;
        }
        return res;
    }
};
// @lc code=end
