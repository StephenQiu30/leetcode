/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<bool>> dp;
    void backtrack(const string &s, int start)
    {
        if (start == s.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = start; i < s.size(); ++i)
        {
            if (dp[start][i])
            {
                path.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        dp = vector<vector<bool>>(n, vector<bool>(n, false));
        // 预处理所有回文子串
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i; j < n; ++j)
            {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = true;
                }
            }
        }

        backtrack(s, 0);
        return res;
    }
};
// @lc code=end
