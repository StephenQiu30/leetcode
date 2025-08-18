/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n) [递归法]
 */

// @lc code=start
class Solution
{
public:
    double quickPow(double x, long long n)
    {
        if (n == 0)
        {
            return 1.0;
        }
        double half = quickPow(x, n / 2);
        if (n % 2 == 0)
        {
            return half * half;
        }
        else
        {
            return half * half * x;
        }
    }

    double myPow(double x, int n)
    {
        long long N = n;
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }
        return quickPow(x, N);
    }
};
// @lc code=end
