/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像 [循环移动]
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int layer = 0; layer < n / 2; layer++)
        {
            int frist = layer;
            int last = n - 1 - layer;
            for (int i = frist; i < last; i++)
            {
                int offset = i - frist;
                int top = matrix[frist][i];

                matrix[frist][i] = matrix[last - offset][frist];
                matrix[last - offset][frist] = matrix[last][last - offset];
                matrix[last][last - offset] = matrix[i][last];
                matrix[i][last] = top;
            }
        }
    }
};
// @lc code=end
