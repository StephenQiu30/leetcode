/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信 [哈希表(计数数组法)]
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int count[26] = {0};
        for (char c : magazine)
        {
            count[c - 'a']++;
        }
        for (char c : ransomNote)
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
