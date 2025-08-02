/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价 [动态规划(优化)]
 */

// @lc code=start
class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            // 买1天票
            dp[i] = dp[i - 1] + costs[0];
            // 买7天票
            int j = i;
            while (j > 0 && days[i - 1] - days[j - 1] < 7)
            {
                j--;
            }
            dp[i] = min(dp[i], dp[j] + costs[1]);
            // 买30天票
            j = i;
            while (j > 0 && days[i - 1] - days[j - 1] < 30)
            {
                j--;
            }
            dp[i] = min(dp[i], dp[j] + costs[2]);
        }
        return dp[n];
    }
};
// @lc code=end
