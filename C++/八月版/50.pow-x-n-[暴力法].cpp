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
        for (long long i = 0; i < N; i++)
        {
            res *= x;
        }
        return res;
    }
};
// @lc code=end
