/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度 [倒叙排序]
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int length = 0;
        int i = s.size() - 1;
        // 先跳过末尾的空格
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }
        // 计算最后一个单词的长度
        while (i >= 0 && s[i] != ' ')
        {
            length++;
            i--;
        }
        return length;
    }
};
// @lc code=end
