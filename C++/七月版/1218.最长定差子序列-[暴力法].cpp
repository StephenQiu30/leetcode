/*
 * @lc app=leetcode.cn id=1218 lang=cpp
 *
 * [1218] 最长定差子序列 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        int n = arr.size(), res = 0;
        for (int i = 0; i < n; ++i)
        {
            int cnt = 1, curr = arr[i];
            for (int j = i + 1; j < n; ++j)
            {
                if (arr[j] == curr + difference)
                {
                    curr = arr[j];
                    cnt++;
                }
            }
            res = max(res, cnt);
        }
        return res;
    }
};
// @lc code=end
