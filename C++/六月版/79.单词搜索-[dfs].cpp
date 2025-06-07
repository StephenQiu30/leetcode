/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索 [dfs]
 */

// @lc code=start
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (dfs(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> &board, string word, int i, int j, int index)
    {
        if (index == word.size())
        {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index])
        {
            return false;
        }

        char temp = board[i][j];
        // 标记为已访问
        board[i][j] = '#';
        // 递归搜索四个方向
        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);
        // 回溯，恢复原值
        board[i][j] = temp;
        return found;
    }
};
// @lc code=end
