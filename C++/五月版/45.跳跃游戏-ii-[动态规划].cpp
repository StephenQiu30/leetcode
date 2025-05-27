/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II [动态规划]
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 1; j <= nums[i] && i + j < n; j++)
            {
                if (dp[i + j] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i + j] + 1);
                }
            }
        }
        return dp[0];
    }
};
// @lc code=end
