/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }

        int minLength = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; ++j)
            {
                sum += nums[j];
                if (sum >= target)
                {
                    minLength = min(minLength, j - i + 1);
                    break;
                }
            }
        }
        return (minLength == INT_MAX) ? 0 : minLength;
    }
};
// @lc code=end
