/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n < 3)
        {
            return 0;
        }
        int best = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = i + 1; j < n - 1; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    if (abs(sum - target) < abs(best - target))
                    {
                        best = sum;
                    }
                }
            }
        }
        return best;
    }
};
// @lc code=end
