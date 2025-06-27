/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和 [滚动数组]
 */

// @lc code=start
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<int> prev(matrix[0]);
        for (int i = 1; i < n; i++)
        {
            vector<int> current(n, __INT_MAX__);
            for (int j = 0; j < n; j++)
            {
                current[j] = matrix[i][j] + prev[j];
                if (j > 0)
                {
                    current[j] = min(current[j], matrix[i][j] + prev[j - 1]);
                }
                if (j < n - 1)
                {
                    current[j] = min(current[j], matrix[i][j] + prev[j + 1]);
                }
            }
            prev = current;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
// @lc code=end
