/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列 [暴力枚举]
 */

// @lc code=start
class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        int res = 2;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int len = 2;
                int d = nums[j] - nums[i];
                int prev = nums[j];
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[k] - prev == d)
                    {
                        len++;
                        prev = nums[k];
                    }
                }
                res = max(res, len);
            }
        }
        return res;
    }
};
// @lc code=end
