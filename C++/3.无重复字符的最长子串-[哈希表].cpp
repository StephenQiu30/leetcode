/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串 [哈希表]
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // 记录字符串上次出现的位置
        unordered_map<char, int> lastIndex;
        int maxLength = 0;
        int left = 0;
        for (int right = 0; right < s.length(); right++)
        {
            if (lastIndex.count(s[right]) && lastIndex[s[right]] >= left)
            {
                // 如果字符重复，更新左指针
                left = lastIndex[s[right]] + 1;
            }
            // 更新字符索引
            lastIndex[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
// @lc code=end
