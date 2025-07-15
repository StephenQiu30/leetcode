/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.length();
        if (n == 0 || s[0] == '0')
        {
            return 0;
        }
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] != '0')
            {
                dp[i] += dp[i - 1];
            }
            int twoDight = stoi(s.substr(i - 2, 2));
            if (twoDight >= 10 && twoDight <= 26)
            {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
// @lc code=end
