/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索 [dfs + visted]
 */

// @lc code=start
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        // 记录访问状态
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dfs(board, word, visited, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> &board, const string &word,
             vector<vector<bool>> &visited, int i, int j, int index)
    {
        if (index == word.size())
        {
            // 成功找到整个单词
            return true;
        }
        int m = board.size(), n = board[0].size();
        // 越界、字符不匹配或访问过
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] != word[index])
        {
            return false;
        }
        // 标记访问
        visited[i][j] = true;

        // 四个方向递归
        bool found = dfs(board, word, visited, i + 1, j, index + 1) ||
                     dfs(board, word, visited, i - 1, j, index + 1) ||
                     dfs(board, word, visited, i, j + 1, index + 1) ||
                     dfs(board, word, visited, i, j - 1, index + 1);
        // 回溯，撤销标记
        visited[i][j] = false;
        return found;
    }
};
// @lc code=end
