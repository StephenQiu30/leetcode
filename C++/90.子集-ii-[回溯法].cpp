/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II [回溯法]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> path;
        // 排序确保相同元素相邻
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, path, result);
        return result;
    }

private:
    void backtrack(vector<int> &nums, int start, vector<int> &path, vector<vector<int>> &result)
    {
        result.push_back(path);
        for (int i = start; i < nums.size(); i++)
        {
            // 关键去重：跳过同层的相同元素
            if (i > start && nums[i] == nums[i - 1])
            {
                continue;
            }
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, result);
            path.pop_back();
        }
    }
};
// @lc code=end
