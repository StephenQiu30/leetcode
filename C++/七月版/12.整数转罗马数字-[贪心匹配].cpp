/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字 [贪心匹配]
 */

// @lc code=start
class Solution
{
public:
    string intToRoman(int num)
    {
        vector<pair<int, string>> valueSymbols = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        string result;
        for (const auto &[value, symbol] : valueSymbols)
        {
            while (num >= value)
            {
                result += symbol;
                num -= value;
            }
        }
        return result;
    }
};
// @lc code=end
