/*
 * @lc app=leetcode.cn id=1323 lang=cpp
 *
 * [1323] 6 和 9 组成的最大数字 [字符串贪心]
 */

// @lc code=start
class Solution
{
public:
    int maximum69Number(int num)
    {
        string s = to_string(num);
        for (char &c : s)
        {
            if (c == '6')
            {
                c = '9';
                break;
            }
        }
        return stoi(s);
    }
};
// @lc code=end
