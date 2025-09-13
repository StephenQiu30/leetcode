/*
 * @lc app=leetcode.cn id=790 lang=cpp
 *
 * [790] 多米诺和托米诺平铺 [动态规划]
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
        vector<long long> f(n + 1), g(n + 1);
        f[0] = 1;
        f[1] = 1;
        g[0] = 0;
        g[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            g[i] = (g[i - 1] + f[i - 2]) % MOD;
            f[i] = (f[i - 1] + f[i - 2] + 2 * g[i - 1]) % MOD;
        }
        return (int)f[n];
    }
};
// @lc code=end
