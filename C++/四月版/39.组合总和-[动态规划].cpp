/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<vector<int>>> dp(target + 1);
        dp[0] = {{}};
        // 先排序以便去重
        sort(candidates.begin(), candidates.end());
        for (int num : candidates)
        {
            for (int i = num; i <= target; i++)
            {
                for (auto comb : dp[i - num])
                {
                    if (!comb.empty() && num < comb.back())
                    {
                        continue;
                    }
                    comb.push_back(num);
                    dp[i].push_back(comb);
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end
