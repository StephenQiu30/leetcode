/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II [数学公式法]
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res(rowIndex + 1, 1);
        for (int j = 1; j < rowIndex; j++)
        {
            res[j] = (long long)res[j - 1] * (rowIndex - j + 1) / j;
        }
        return res;
    }
};
// @lc code=end
