/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期 [动态规划(状态压缩)]
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }
        // 持股
        int hold = -prices[0];
        // 刚卖出
        int sold = 0;
        // 休息
        int rest = 0;
        for (int i = 1; i < n; i++)
        {
            int pre_hold = hold;
            int pre_sold = sold;
            int pre_rest = rest;

            hold = max(pre_hold, pre_rest - prices[i]);
            sold = pre_hold + prices[i];
            rest = max(pre_rest, pre_sold);
        }
        // 最后一天不能持有股票
        return max(sold, rest);
    }
};
// @lc code=end
