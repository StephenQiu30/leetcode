/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律 [双向映射]
 */

// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> words;
        istringstream iss(s);
        string word;
        while (iss >> word)
        {
            words.push_back(word);
        }
        if (words.size() != pattern.size())
        {
            return false;
        }
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        for (int i = 0; i < pattern.size(); i++)
        {
            char c = pattern[i];
            const string &w = words[i];
            if (charToWord.count(c) && charToWord[c] != w)
            {
                return false;
            }
            if (wordToChar.count(w) && wordToChar[w] != c)
            {
                return false;
            }
            charToWord[c] = w;
            wordToChar[w] = c;
        }
        return true;
    }
};
// @lc code=end
