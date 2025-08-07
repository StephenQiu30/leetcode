/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域 [BFS]
 */

// @lc code=start
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        if (m == 0)
        {
            return;
        }
        int n = board[0].size();
        queue<pair<int, int>> q;
        // 把边界上的 'O' 加入队列
        for (int i = 0; i < m; ++i)
        {
            if (board[i][0] == 'O')
            {
                q.emplace(i, 0);
            }
            if (board[i][n - 1] == 'O')
            {
                q.emplace(i, n - 1);
            }
        }
        for (int j = 0; j < n; ++j)
        {
            if (board[0][j] == 'O')
            {
                q.emplace(0, j);
            }
            if (board[m - 1][j] == 'O')
            {
                q.emplace(m - 1, j);
            }
        }
        // 广度优先搜索
        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O')
            {
                continue;
            }
            board[i][j] = '#';
            q.emplace(i - 1, j);
            q.emplace(i + 1, j);
            q.emplace(i, j - 1);
            q.emplace(i, j + 1);
        }
        // 遍历修改
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
// @lc code=end
