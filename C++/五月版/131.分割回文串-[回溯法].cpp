/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串 [回溯法]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<string>> partition(string s)
    {
        backtrack(s, 0);
        return res;
    }
    void backtrack(const string &s, int start)
    {
        if (start == s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            if (isPalindrome(s, start, i))
            {
                path.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1);
                // 回溯
                path.pop_back();
            }
        }
    }
    bool isPalindrome(const string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
