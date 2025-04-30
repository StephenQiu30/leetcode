/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II [二分查找]
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        for (const auto &row : matrix)
        {
            if (binary_search(row.begin(), row.end(), target))
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
