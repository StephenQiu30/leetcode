/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.back();
        vector<int> dp(n + 1, 0);
        unordered_set<int> travel(days.begin(), days.end());
        for (int i = 1; i <= n; i++)
        {
            if (!travel.count(i))
            {
                dp[i] = dp[i - 1];
            }
            else
            {
                dp[i] = min({dp[i - 1] + costs[0],
                             dp[max(0, i - 7)] + costs[1],
                             dp[max(0, i - 30)] + costs[2]});
            }
        }
        return dp[n];
    }
};
// @lc code=end
