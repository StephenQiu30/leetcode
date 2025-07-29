/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词 [双指针法]
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        // 去掉首尾和多余中间空格
        removeExtraSpaces(s);
        // 反转整个字符串
        reverse(s.begin(), s.end());
        // 反转每个单词
        int start = 0;
        for (int end = 0; end <= s.size(); end++)
        {
            if (end == s.size() || s[end] == ' ')
            {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
        return s;
    }

private:
    void removeExtraSpaces(string &s)
    {
        int slow = 0, n = s.size();
        for (int fast = 0; fast < n; fast++)
        {
            if (s[fast] != ' ')
            {
                if (slow != 0)
                {
                    s[slow++] = ' ';
                }
                while (fast < n && s[fast] != ' ')
                {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
    }
};
// @lc code=end
