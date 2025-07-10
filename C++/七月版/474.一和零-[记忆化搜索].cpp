/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零 [记忆化搜索]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<vector<int>>> memo;
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        memo = vector<vector<vector<int>>>(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return dfs(strs, 0, m, n);
    }
    int dfs(vector<string> &strs, int i, int m, int n)
    {
        if (i == strs.size())
        {
            return 0;
        }
        if (memo[i][m][n] != -1)
        {
            return memo[i][m][n];
        }
        int zeros = count(strs[i].begin(), strs[i].end(), '0');
        int ones = strs[i].size() - zeros;
        int not_pick = dfs(strs, i + 1, m, n);
        int pick = 0;
        if (m >= zeros && n >= ones)
        {
            pick = 1 + dfs(strs, i + 1, m - zeros, n - ones);
        }

        return memo[i][m][n] = max(pick, not_pick);
    }
};
// @lc code=end
