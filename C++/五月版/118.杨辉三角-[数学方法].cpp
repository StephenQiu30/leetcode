/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角 [数学方法]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> row(i + 1, 1);
            long long val = 1;
            for (int j = 1; j < i; j++)
            {
                val = val * (i - j + 1) / j;
                row[j] = val;
            }
            res.push_back(row);
        }
        return res;
    }
};
// @lc code=end
