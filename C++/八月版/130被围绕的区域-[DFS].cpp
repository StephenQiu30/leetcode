/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域 [DFS]
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

        function<void(int, int)> dfs = [&](int i, int j)
        {
            if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O')
            {
                return;
            }
            // 标记为不可替换
            board[i][j] = '#';
            dfs(i - 1, j);
            dfs(i + 1, j);
            dfs(i, j - 1);
            dfs(i, j + 1);
        };
        // 从边界开始 dfs
        for (int i = 0; i < m; i++)
        {
            dfs(i, 0);
            dfs(i, n - 1);
        }
        for (int j = 0; j < n; j++)
        {
            dfs(0, j);
            dfs(m - 1, j);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
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
