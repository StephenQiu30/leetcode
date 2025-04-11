/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合 [递归回溯]
 */

// @lc code=start
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return {};
        }
        vector<string> phoneMap = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string path;
        backtrack(digits, 0, path, res, phoneMap);
        return res;
    }

private:
    void backtrack(const string &digits, int index, string &path, vector<string> &res, vector<string> &phoneMap)
    {
        if (index == digits.size())
        {
            res.push_back(path);
            return;
        }
        string letters = phoneMap[digits[index] - '0'];
        for (char ch : letters)
        {
            path.push_back(ch);
            backtrack(digits, index + 1, path, res, phoneMap);
            path.pop_back();
        }
    }
};
// @lc code=end
