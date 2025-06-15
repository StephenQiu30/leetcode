/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子 [带时间戳的BFS]
 */

// @lc code=start
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> queue;
        // 初始化队列，统计新鲜橘子
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                {
                    queue.push({i, j});
                }
            }
        }
        int minutes = 0;
        vector<pair<int, int>> dirs = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}};
        while (!queue.empty())
        {
            auto [x, y] = queue.front();

            queue.pop();
            for (auto [dx, dy] : dirs)
            {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1)
                {
                    grid[nx][ny] = grid[x][y] + 1;
                    queue.push({nx, ny});
                }
            }
        }
        int maxTime = 0;
        for (auto &row : grid)
        {
            for (int cell : row)
            {
                if (cell == 1)
                {
                    return -1;
                }
                maxTime = max(maxTime, cell);
            }
        }
        return maxTime > 2 ? maxTime - 2 : 0;
    }
};
// @lc code=end
