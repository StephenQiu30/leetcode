/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列 [递归]
 */

// @lc code=start
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dfs(text1, text2, m - 1, n - 1, memo);
    }
    int dfs(const string &t1, const string &t2, int i, int j, vector<vector<int>> &memo)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }

        if (t1[i] == t2[j])
        {
            memo[i][j] = dfs(t1, t2, i - 1, j - 1, memo) + 1;
        }
        else
        {
            memo[i][j] = max(dfs(t1, t2, i - 1, j, memo), dfs(t1, t2, i, j - 1, memo));
        }
        return memo[i][j];
    }
};
// @lc code=end
