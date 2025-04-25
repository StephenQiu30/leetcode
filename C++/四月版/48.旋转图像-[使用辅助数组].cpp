/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像 [使用辅助数组]
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> result(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[j][n - 1 - i] = matrix[i][j];
            }
        }
        matrix = result;
    }
};
// @lc code=end
