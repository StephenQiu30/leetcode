/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列 [递归]
 */

// @lc code=start
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dfs(0, n - 1, s, memo);
    }
    int dfs(int i, int j, const string &s, vector<vector<int>> &memo)
    {
        if (i > j)
        {
            return 0;
        }
        if (i == j)
        {
            return 1;
        }
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }
        if (s[i] == s[j])
        {
            memo[i][j] = dfs(i + 1, j - 1, s, memo) + 2;
        }
        else
        {
            memo[i][j] = max(dfs(i + 1, j, s, memo), dfs(i, j - 1, s, memo));
        }
        return memo[i][j];
    }
};
// @lc code=end
