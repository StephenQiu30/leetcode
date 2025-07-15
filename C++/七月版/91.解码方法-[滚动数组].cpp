/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法 [滚动数组]
 */

// @lc code=start
class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.length();
        if (n == 0 || s[0] == '0')
        {
            return 0;
        }
        int prev2 = 1;
        int prev1 = 1;
        for (int i = 1; i < n; i++)
        {
            int current = 0;
            if (s[i] != '0')
            {
                current += prev1;
            }
            int twoDight = stoi(s.substr(i - 1, 2));
            if (twoDight >= 10 && twoDight <= 26)
            {
                current += prev2;
            }
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};
// @lc code=end
