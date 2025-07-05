/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        unordered_map<int, int> dp;
        int maxLength = 0;
        for (int x : arr)
        {
            dp[x] = dp[x - difference] + 1;
            maxLength = max(maxLength, dp[x]);
        }
        return maxLength;
    }
};
// @lc code=end
