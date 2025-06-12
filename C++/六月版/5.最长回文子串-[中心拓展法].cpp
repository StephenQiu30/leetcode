/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串 [中心拓展法]
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int start = 0, maxLength = 0;
        int n = s.size();
        auto expend = [&](int l, int r)
        {
            while (l >= 0 && r < n && s[l] == s[r])
            {
                --l;
                ++r;
            }
            return make_pair(l + 1, r - l - 1);
        };
        for (int i = 0; i < n; i++)
        {
            auto [l1, len1] = expend(i, i);
            auto [l2, len2] = expend(i, i + 1);
            if (len1 > maxLength)
            {
                start = l1;
                maxLength = len1;
            }
            if (len2 > maxLength)
            {
                start = l2;
                maxLength = len2;
            }
        }
        return s.substr(start, maxLength);
    }
};
// @lc code=end
