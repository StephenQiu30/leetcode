/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信 [哈希表]
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> frequency;
        for (char c : magazine)
        {
            frequency[c]++;
        }
        for (char c : ransomNote)
        {
            if (--frequency[c] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
