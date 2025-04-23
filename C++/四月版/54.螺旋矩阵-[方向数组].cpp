/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵 [方向数组]
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> res;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, dir = 0;
        for (int i = 0; i < m * n; ++i)
        {
            res.push_back(matrix[x][y]);
            visited[x][y] = true;
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny])
            {
                x = nx;
                y = ny;
            }
            else
            {
                // 变换方向
                dir = (dir + 1) % 4;
                x += dx[dir];
                y += dy[dir];
            }
        }
        return res;
    }
};
// @lc code=end
