/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        // 最长递增子序列长度
        vector<int> dp(n, 1);
        // 对应的个数
        vector<int> cnt(n, 1);
        int maxLen = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        // 重新计数
                        cnt[i] = cnt[j];
                    }
                    else if (dp[j] + 1 == dp[i])
                    {
                        // 累加方案数
                        cnt[i] += cnt[j];
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxLen)
            {
                res += cnt[i];
            }
        }
        return res;
    }
};
// @lc code=end
