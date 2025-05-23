/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分 [DFS]
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> memo;
        return dfs(s, 0, dict, memo);
    }

    bool dfs(const string &s, int start, unordered_set<string> &dict, unordered_map<int, bool> &memo)
    {
        if (start == s.length())
        {
            return true;
        }

        if (memo.count(start))
        {
            return memo[start];
        }

        for (int end = start + 1; end <= s.length(); ++end)
        {
            if (dict.count(s.substr(start, end - start)) && dfs(s, end, dict, memo))
            {
                return memo[start] = true;
            }
        }

        return memo[start] = false;
    }
};
// @lc code=end
