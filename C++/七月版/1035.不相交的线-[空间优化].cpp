/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线 [动态规划（空间优化）]
 */

// @lc code=start
class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            int prev = 0;
            for (int j = 1; j <= n; j++)
            {
                int temp = dp[j];
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[j] = prev + 1;
                }
                else
                {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }
        return dp[n];
    }
};
// @lc code=end
