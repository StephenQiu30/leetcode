/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯 [递归]
 */

// @lc code=start
class Solution
{
public:
    int dp[1001];
    int minCostClimbingStairs(vector<int> &cost)
    {
        memset(dp, -1, sizeof(dp));
        return dfs(cost.size(), cost);
    }
    int dfs(int i, vector<int> &cost)
    {
        if (i <= 1)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        return dp[i] = min(dfs(i - 1, cost) + cost[i - 1],
                           dfs(i - 2, cost) + cost[i - 2]);
    }
};
// @lc code=end
