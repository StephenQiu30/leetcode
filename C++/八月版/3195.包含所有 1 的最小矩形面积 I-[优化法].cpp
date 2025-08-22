/*
 * @lc app=leetcode.cn id=3195 lang=cpp
 *
 * [3195] 包含所有 1 的最小矩形面积 I [优化法]
 */

// @lc code=start
class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int minRow = 0, maxRow = m - 1;
        int minCol = 0, maxCol = n - 1;
        // 找最上面的行
        while (minRow <= maxRow && all_of(grid[minRow].begin(), grid[minRow].end(), [](int x)
                                          { return x == 0; }))
        {
            minRow++;
        }
        // 找最下面的行
        while (maxRow >= minRow && all_of(grid[maxRow].begin(), grid[maxRow].end(), [](int x)
                                          { return x == 0; }))
        {
            maxRow--;
        }
        // 找最左边的列
        while (minCol <= maxCol)
        {
            bool allZero = true;
            for (int i = minRow; i <= maxRow; i++)
            {
                if (grid[i][minCol] == 1)
                {
                    allZero = false;
                    break;
                }
            }
            if (!allZero)
            {
                break;
            }
            minCol++;
        }
        // 找最右边的列
        while (maxCol >= minCol)
        {
            bool allZero = true;
            for (int i = minRow; i <= maxRow; i++)
            {
                if (grid[i][maxCol] == 1)
                {
                    allZero = false;
                    break;
                }
            }
            if (!allZero)
            {
                break;
            }
            maxCol--;
        }

        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};
// @lc code=end
