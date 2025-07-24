/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串 [哈希表]
 */

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        unordered_map<char, char> s2t, t2s;
        for (int i = 0; i < s.length(); i++)
        {
            char a = s[i], b = t[i];
            if ((s2t.count(a) && s2t[a] != b) || (t2s.count(b) && t2s[b] != a))
            {
                return false;
            }
            s2t[a] = b;
            t2s[b] = a;
        }
        return true;
    }
};
// @lc code=end
