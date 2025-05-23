/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && dict.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
// @lc code=end
