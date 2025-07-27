/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词 [哈希表法]
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
        int count[26] = {0};
        for (char c : s)
        {
            count[c - 'a']++;
        }
        for (char c : t)
        {
            if (--count[c - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
