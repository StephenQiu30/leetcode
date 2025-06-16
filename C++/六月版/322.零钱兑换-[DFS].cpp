/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换 [DFS]
 */

// @lc code=start
class Solution
{
public:
    int dfs(int amount, vector<int> &coins, vector<int> &memo)
    {
        if (amount < 0)
        {
            return -1;
        }
        if (amount == 0)
        {
            return 0;
        }
        if (memo[amount] != -2)
        {
            return memo[amount];
        }
        int res = INT_MAX;
        for (int coin : coins)
        {
            int sub = dfs(amount - coin, coins, memo);
            if (sub != -1)
            {
                res = min(res, sub + 1);
            }
        }
        memo[amount] = (res == INT_MAX) ? -1 : res;
        return memo[amount];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        // -2 表示未计算，-1 表示无法凑出
        vector<int> memo(amount + 1, -2);
        return dfs(amount, coins, memo);
    }
};
// @lc code=end
