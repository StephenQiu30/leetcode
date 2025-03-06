/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集 [DFS(深度优先算法)]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> path;
        dfs(nums, 0, path, result);
        return result;
    }

private:
    void dfs(vector<int> &nums, int index, vector<int> &path, vector<vector<int>> &result)
    {
        // 递归终止条件
        if (index == nums.size())
        {
            result.push_back(path);
            return;
        }

        // 不选择当前元素
        dfs(nums, index + 1, path, result);

        // 选择当前元素
        path.push_back(nums[index]);
        dfs(nums, index + 1, path, result);

        // 回溯
        path.pop_back();
    }
};
// @lc code=end
