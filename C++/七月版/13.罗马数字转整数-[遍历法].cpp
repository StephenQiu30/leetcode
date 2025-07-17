/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数 [遍历法]
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int current = roman[s[i]];
            int next = (i + 1 < s.size()) ? roman[s[i + 1]] : 0;
            if (current < next)
            {
                result -= current;
            }
            else
            {
                result += current;
            }
        }
        return result;
    }
};
// @lc code=end
