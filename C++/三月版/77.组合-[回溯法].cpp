/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合 [回溯法]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(n, k, 1, path, result);
        return result;
    }

private:
    void backtrack(int n, int k, int start, vector<int> &path, vector<vector<int>> &result)
    {
        // 递归结束的条件
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            path.push_back(i);
            backtrack(n, k, i + 1, path, result);
            // 回溯
            path.pop_back();
        }
    }
};
// @lc code=end
