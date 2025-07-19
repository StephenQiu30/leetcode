/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串 [过滤]
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string filtered;
        for (char c : s)
        {
            if (isalnum(c))
            {
                filtered += tolower(c);
            }
        }
        string reversed = filtered;
        reverse(reversed.begin(), reversed.end());
        return filtered == reversed;
    }
};
// @lc code=end
