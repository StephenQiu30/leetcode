/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串 [DFS]
 */

// @lc code=start
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size())
        {
            return false;
        }
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return dfs(s1, s2, s3, 0, 0, memo);
    }

    bool dfs(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>> &memo)
    {
        if (i + j == s3.size())
        {
            return true;
        }
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }

        bool ans = false;
        if (i < s1.size() && s1[i] == s3[i + j])
        {
            ans = dfs(s1, s2, s3, i + 1, j, memo);
        }
        if (!ans && j < s2.size() && s2[j] == s3[i + j])
        {
            ans = dfs(s1, s2, s3, i, j + 1, memo);
        }
        return memo[i][j] = ans;
    }
};
// @lc code=end
