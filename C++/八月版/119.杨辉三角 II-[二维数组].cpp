/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II [二维数组]
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res(rowIndex + 1, 0);
        res[0] = 1;
        for (int i = 0; i <= rowIndex; i++)
        {
            for (int j = i; j >= 1; j--)
            {
                res[j] += res[j - 1];
            }
        }
        return res;
    }
};
// @lc code=end
