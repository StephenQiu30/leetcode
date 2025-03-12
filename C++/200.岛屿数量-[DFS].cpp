/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量 [DFS]
 */

// @lc code=start
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
        {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

private:
    void dfs(vector<vector<char>> &grid, int r, int c)
    {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0')
        {
            // 超出边界或者已经访问过
            return;
        }
        // 标记为已访问
        grid[r][c] = '0';
        // 向四个方向扩展
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }
};
// @lc code=end
