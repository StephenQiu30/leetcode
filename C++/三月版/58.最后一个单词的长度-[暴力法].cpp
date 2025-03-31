/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int length = 0;
        bool inWord = false;
        for (char c : s)
        {
            if (c == ' ')
            {
                inWord = false;
            }
            else
            {
                if (!inWord)
                {
                    length = 1;
                }
                else
                {
                    length++;
                }
                inWord = true;
            }
        }
        return length;
    }
};
// @lc code=end
