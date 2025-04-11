/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和 [回溯法]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(res, candidates, target, 0, path);
        return res;
    }

private:
    void dfs(vector<vector<int>> &res, vector<int> &candidates, int target, int start, vector<int> &path)
    {
        if (target == 0)
        {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            if (target < candidates[i])
            {
                continue;
            }
            path.push_back(candidates[i]);
            dfs(res, candidates, target - candidates[i], i, path);
            path.pop_back();
        }
    }
};
// @lc code=end
