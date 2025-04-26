/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零 [最优空间]
 */

// @lc code=start
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        // 判断第一列是否有 0
        for (int i = 0; i < m; ++i)
        {
            if (matrix[i][0] == 0)
            {
                firstColZero = true;
                break;
            }
        }

        // 判断第一行是否有 0
        for (int j = 0; j < n; ++j)
        {
            if (matrix[0][j] == 0)
            {
                firstRowZero = true;
                break;
            }
        }

        // 用第一行第一列作为标记
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 根据标记置零
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // 处理第一列
        if (firstColZero)
        {
            for (int i = 0; i < m; ++i)
            {
                matrix[i][0] = 0;
            }
        }

        // 处理第一行
        if (firstRowZero)
        {
            for (int j = 0; j < n; ++j)
            {
                matrix[0][j] = 0;
            }
        }
    }
};
// @lc code=end
