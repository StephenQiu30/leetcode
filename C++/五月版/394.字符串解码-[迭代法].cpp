/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码 [递归法]
 */

// @lc code=start
class Solution
{
public:
    string decodeString(string s)
    {
        int i = 0;
        return decode(s, i);
    }
    string decode(const string &s, int &i)
    {
        string res = "";
        while (i < s.length() && s[i] != ']')
        {
            if (isdigit(s[i]))
            {
                int num = 0;
                while (isdigit(s[i]))
                {
                    num = num * 10 + (s[i++] - '0');
                }
                i++;
                // skip '['
                string t = decode(s, i);
                i++;
                // skip ']'
                while (num--)
                    res += t;
            }
            else
            {
                res += s[i++];
            }
        }
        return res;
    }
};
// @lc code=end
