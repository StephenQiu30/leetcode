/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵 [模拟法]
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        if (matrix.empty())
        {
            return res;
        }
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        while (top <= bottom && left <= right)
        {
            // 从左到右
            for (int i = left; i <= right; i++)
            {
                res.push_back(matrix[top][i]);
            }
            top++;
            // 从上到下
            for (int i = top; i <= bottom; i++)
            {
                res.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom)
            {
                // 从右到左
                for (int i = right; i >= left; i--)
                {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};
// @lc code=end
