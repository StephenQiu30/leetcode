/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律 [位编码法]
 */

// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        istringstream iss(s);
        vector<string> words;
        string word;
        while (iss >> word)
        {
            words.push_back(word);
        }
        if (pattern.size() != words.size())
        {
            return false;
        }
        unordered_map<char, int> charIndex;
        unordered_map<string, int> wordIndex;
        for (int i = 0; i < pattern.size(); i++)
        {
            if (charIndex[pattern[i]] != wordIndex[words[i]])
            {
                return false;
            }
            charIndex[pattern[i]] = i + 1;
            wordIndex[words[i]] = i + 1;
        }
        return true;
    }
};
// @lc code=end
