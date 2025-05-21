/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II [回溯 + 递归 + 剪枝去重]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backtrace(candidates, target, 0);
        return result;
    }

private:
    void backtrace(vector<int> &candidates, int target, int start)
    {
        if (target == 0)
        {
            result.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            // 剪枝：当前数字已经大于剩余目标
            if (candidates[i] > target)
            {
                break;
            }
            if (i > start && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            path.push_back(candidates[i]);
            backtrace(candidates, target - candidates[i], i + 1);
            // 回溯
            path.pop_back();
        }
    }
};
// @lc code=end
