/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换 [数学规律法]
 */

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.size())
        {
            return s;
        }

        string result;
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j + i < s.size(); j += cycleLen)
            {
                result += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < s.size())
                {
                    result += s[j + cycleLen - i];
                }
            }
        }
        return result;
    }
};
// @lc code=end
