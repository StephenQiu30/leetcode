/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费 [记忆化递归]
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));
        return dfs(0, 0, prices, fee, memo);
    }
    int dfs(int i, int hold, vector<int> &prices, int fee, vector<vector<int>> &memo)
    {
        if (i == prices.size())
        {
            return 0;
        }
        if (memo[i][hold] != -1)
        {
            return memo[i][hold];
        }
        int res = 0;
        if (hold)
        {
            //  卖出 或 不动
            res = max(dfs(i + 1, 1, prices, fee, memo), prices[i] - fee + dfs(i + 1, 0, prices, fee, memo));
        }
        else
        {
            res = max(dfs(i + 1, 0, prices, fee, memo), -prices[i] + dfs(i + 1, 1, prices, fee, memo));
        }
        return memo[i][hold] = res;
    }
};
// @lc code=end
