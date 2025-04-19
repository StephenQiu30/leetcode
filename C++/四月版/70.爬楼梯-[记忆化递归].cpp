/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯 [记忆化递归]
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> memo(n + 1, -1);
        return dfs(n, memo);
    }

private:
    int dfs(int n, vector<int> &memo)
    {
        if (n <= 2)
        {
            return n;
        }
        if (memo[n] != -1)
        {
            return memo[n];
        }
        memo[n] = dfs(n - 1, memo) + dfs(n - 2, memo);
        return memo[n];
    }
};
// @lc code=end
