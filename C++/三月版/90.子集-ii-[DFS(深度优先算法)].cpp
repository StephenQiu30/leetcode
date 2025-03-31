/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II [DFS(深度优先算法)]
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
        vector<bool> visited(nums.size(), false);
        dfs(nums, 0, path, result, visited);
        return result;
    }

private:
    void dfs(vector<int> &nums, int start, vector<int> &path, vector<vector<int>> &result, vector<bool> &visited)
    {
        // 加入当前路径
        result.push_back(path);

        for (int i = start; i < nums.size(); i++)
        {
            // 去重：同层相同元素不能重复选择
            if (i > start && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;

            path.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, i + 1, path, result, visited);
            path.pop_back();
            visited[i] = false;
        }
    }
};
// @lc code=end
