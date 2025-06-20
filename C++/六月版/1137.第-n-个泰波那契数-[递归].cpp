/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数 [递归]
 */

// @lc code=start
class Solution
{
public:
    int tribonacci(int n)
    {
        vector<int> memo(n + 1, -1);
        return helper(n, memo);
    }

private:
    int helper(int n, vector<int> &memo)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1 || n == 2)
        {
            return 1;
        }
        if (memo[n] != -1)
        {
            return memo[n];
        }
        memo[n] = helper(n - 1, memo) + helper(n - 2, memo) + helper(n - 3, memo);
        return memo[n];
    }
};
// @lc code=end
