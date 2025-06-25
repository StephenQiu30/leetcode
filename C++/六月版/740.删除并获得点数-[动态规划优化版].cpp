/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数 [动态规划优化版]
 */

// @lc code=start
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int maxValue = *max_element(nums.begin(), nums.end());
        vector<int> sum(maxValue + 1, 0);
        for (int num : nums)
        {
            sum[num] += num;
        }
        int first = sum[0], second = sum[1];
        for (int i = 2; i <= maxValue; i++)
        {
            int current = max(second, first + sum[i]);
            first = second;
            second = current;
        }
        return second;
    }
};
// @lc code=end
