/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II [方向向量]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};
        int dir = 0; // 0:right,1:down,2:left,3:up
        int r = 0, c = 0;
        for (int num = 1; num <= n * n; num++)
        {
            mat[r][c] = num;
            int nr = r + dr[dir], nc = c + dc[dir];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || mat[nr][nc] != 0)
            {
                dir = (dir + 1) % 4;
                nr = r + dr[dir];
                nc = c + dc[dir];
            }
            r = nr;
            c = nc;
        }

        return mat;
    }
};
// @lc code=end
