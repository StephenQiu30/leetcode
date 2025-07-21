/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(26, n));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int c = 0; c < 26; c++)
            {
                if (t[i] - 'a' == c)
                {
                    dp[i][c] = i;
                }
                else
                {
                    dp[i][c] = dp[i + 1][c];
                }
            }
        }
        int position = 0;
        for (char c : s)
        {
            if (dp[position][c - 'a'] == n)
            {
                return false;
            }
            position = dp[position][c - 'a'] + 1;
        }
        return true;
    }
};
// @lc code=end
