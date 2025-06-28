/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形 [动态规划(空间优化)]
 */

// @lc code=start
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> prev(cols, 0), current(cols, 0);
        int maxLength = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == '1')
                {
                    if (i == 0 || j == 0)
                    {
                        current[j] = 1;
                    }
                    else
                    {
                        current[j] = min({prev[j], current[j - 1], prev[j - 1]}) + 1;
                    }
                    maxLength = max(maxLength, current[j]);
                }
                else
                {
                    current[j] = 0;
                }
            }
            prev.swap(current);
        }
        return maxLength * maxLength;
    }
};
// @lc code=end
