/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)
        {
            return "";
        }
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, maxLength = 1;
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }
        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                if (s[i] == s[j])
                {
                    if (len == 2)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    if (dp[i][j] && len > maxLength)
                    {
                        maxLength = len;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLength);
    }
};
// @lc code=end
