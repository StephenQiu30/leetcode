/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词 [滑动窗口]
 */

// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        if (s.size() < p.size())
        {
            return res;
        }
        vector<int> need(26, 0), window(26, 0);
        for (char c : p)
        {
            need[c - 'a']++;
        }
        int left = 0, right = 0;
        while (right < s.size())
        {
            window[s[right] - 'a']++;
            if (right - left + 1 == p.size())
            {
                if (window == need)
                {
                    res.push_back(left);
                }
                window[s[left] - 'a']--;
                left++;
            }
            right++;
        }
        return res;
    }
};
// @lc code=end
