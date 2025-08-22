/*
 * @lc app=leetcode.cn id=3195 lang=cpp
 *
 * [3195] 包含所有 1 的最小矩形面积 I [直接遍历法]
 */

// @lc code=start
class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int minRow = m, maxRow = -1, minCol = n, maxCol = -1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};
// @lc code=end
