/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II [边界模拟]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int num = 1;
        while (left <= right && top <= bottom)
        {
            // top row: left -> right
            for (int j = left; j <= right; ++j)
            {
                mat[top][j] = num++;
            }
            ++top;
            // right col: top -> bottom
            for (int i = top; i <= bottom; ++i)
            {
                mat[i][right] = num++;
            }
            --right;
            // bottom row: right -> left (注意边界)
            if (top <= bottom)
            {
                for (int j = right; j >= left; --j)
                {
                    mat[bottom][j] = num++;
                }
                --bottom;
            }
            // left col: bottom -> top (注意边界)
            if (left <= right)
            {
                for (int i = bottom; i >= top; --i)
                {
                    mat[i][left] = num++;
                }
                ++left;
            }
        }
        return mat;
    }
};
// @lc code=end
