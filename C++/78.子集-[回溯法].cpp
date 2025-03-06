/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集 [回溯法]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> path;
        backtrace(nums, 0, path, result);
        return result;
    }

private:
    void backtrace(vector<int> &nums, int start, vector<int> &path, vector<vector<int>> &result)
    {
        int n = nums.size();
        // 每个路径都是一个子集
        result.push_back(path);
        for (int i = start; i < n; i++)
        {
            path.push_back(nums[i]);
            backtrace(nums, i + 1, path, result);
            path.pop_back();
        }
    }
};
// @lc code=end
