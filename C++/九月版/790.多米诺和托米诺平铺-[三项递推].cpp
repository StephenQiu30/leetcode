/*
 * @lc app=leetcode.cn id=790 lang=cpp
 *
 * [790] 多米诺和托米诺平铺 [三项递推]
 */

// @lc code=start
class Solution
{
public:
    int numTilings(int n)
    {
        const long long MOD = 1000000007LL;
        if (n == 0 || n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        // f[0]
        long long f0 = 1;
        // f[1]
        long long f1 = 1;
        // f[2]
        long long f2 = 2;
        for (int i = 3; i <= n; i++)
        {
            // f[i] = 2*f[i-1] + f[i-3]
            long long fi = (2 * f2 + f0) % MOD;
            f0 = f1;
            f1 = f2;
            f2 = fi;
        }
        return (int)f2;
    }
};
// @lc code=end
