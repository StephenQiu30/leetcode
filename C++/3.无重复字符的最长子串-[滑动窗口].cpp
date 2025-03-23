/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串 [滑动窗口]
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> window;
        int maxLength = 0;
        int left = 0;
        for (int right = 0; right < s.length(); right++)
        {
            // 窗口中存在重复的元素
            while (window.count(s[right]))
            {
                // 移除左侧的字符串
                window.erase(s[left]);
                ++left;
            }
            // 加入新的字符串
            window.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
// @lc code=end
