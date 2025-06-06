/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集 [递归]
 */

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
        {
            return false;
        }
        int target = sum / 2;
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(target + 1, -1));
        return dfs(nums, n - 1, target, memo);
    }
    bool dfs(vector<int> &nums, int index, int target, vector<vector<int>> &memo)
    {
        if (target == 0)
        {
            return true;
        }
        if (index < 0 || target < 0)
        {
            return false;
        }
        if (memo[index][target] != -1)
        {
            return memo[index][target];
        }
        bool include = dfs(nums, index - 1, target - nums[index], memo);
        bool exclude = dfs(nums, index - 1, target, memo);

        memo[index][target] = include || exclude;
        return memo[index][target];
    }
};
// @lc code=end
