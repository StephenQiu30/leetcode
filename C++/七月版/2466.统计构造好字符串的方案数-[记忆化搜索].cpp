/*
 * @lc app=leetcode.cn id=2466 lang=cpp
 *
 * [2466] 统计构造好字符串的方案数 [记忆化搜索]
 */

// @lc code=start
class Solution
{
public:
    const int MOD = 1e9 + 7;
    vector<int> memo;
    int countGoodStrings(int low, int high, int zero, int one)
    {
        memo = vector<int>(high + 1, -1);
        return dfs(0, low, high, zero, one);
    }
    int dfs(int len, int low, int high, int zero, int one)
    {
        if (len > high)
        {
            return 0;
        }
        if (memo[len] != -1)
        {
            return memo[len];
        }
        long long res = (len >= low) ? 1 : 0;

        res = (res + dfs(len + zero, low, high, zero, one)) % MOD;
        res = (res + dfs(len + one, low, high, zero, one)) % MOD;

        return memo[len] = res;
    }
};
// @lc code=end
