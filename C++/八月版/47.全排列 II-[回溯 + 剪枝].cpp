/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II [回溯 + 剪枝]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used;

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        used.assign(nums.size(), false);
        backtrack(nums);
        return res;
    }
    void backtrack(vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i])
            {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums);
            path.pop_back();
            used[i] = false;
        }
    }
};
// @lc code=end
