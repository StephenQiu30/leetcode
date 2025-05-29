/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机 [贪心算法]
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int price : prices)
        {
            if (price < minPrice)
            {
                minPrice = price;
            }
            else
            {
                maxProfit = max(maxProfit, price - minPrice);
            }
        }
        return maxProfit;
    }
};
// @lc code=end
