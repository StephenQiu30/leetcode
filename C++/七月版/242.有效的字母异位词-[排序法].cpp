/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词 [排序法]
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
// @lc code=end
