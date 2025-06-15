/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子 [多源BFS]
 */

// @lc code=start
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> queue;
        int fresh = 0;
        // 初始化队列，统计新鲜橘子
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                {
                    queue.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        if (fresh == 0)
        {
            // 没有新鲜橘子
            return 0;
        }
        int minutes = 0;
        vector<pair<int, int>> dirs = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}};
        while (!queue.empty())
        {
            int size = queue.size();
            bool rotted = false;
            for (int i = 0; i < size; i++)
            {
                auto [x, y] = queue.front();
                queue.pop();
                for (auto [dx, dy] : dirs)
                {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        queue.push({nx, ny});
                        fresh--;
                        rotted = true;
                    }
                }
            }
            if (rotted)
            {
                minutes++;
            }
        }
        return fresh == 0 ? minutes : -1;
    }
};
// @lc code=end
