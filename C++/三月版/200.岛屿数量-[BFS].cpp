/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量 [BFS]
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
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }

private:
    void bfs(vector<vector<char>> &grid, int r, int c)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        // 标记为已访问
        grid[r][c] = '0';
        //
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions)
            {
                int newX = x + dx, newY = y + dy;
                if (newX >= 0 && newY >= 0 && newX < m && newY < n && grid[newX][newY] == '1')
                {
                    q.push({newX, newY});
                    // 标记访问
                    grid[newX][newY] = '0';
                }
            }
        }
    }
};
// @lc code=end
