/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ [记忆化递归]
 */

// @lc code=start
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> memo(target + 1, -1);
        return dfs(nums, target, memo);
    }
    int dfs(vector<int> &nums, int target, vector<int> &memo)
    {
        if (target == 0)
        {
            return 1;
        }
        if (target < 0)
        {
            return 0;
        }
        if (memo[target] != -1)
        {
            return memo[target];
        }
        int res = 0;
        for (int num : nums)
        {
            res += dfs(nums, target - num, memo);
        }
        memo[target] = res;
        return res;
    }
};
// @lc code=end
