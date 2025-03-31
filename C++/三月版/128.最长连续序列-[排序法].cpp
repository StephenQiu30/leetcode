/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列 [排序法]
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int longest = 1, currentSteak = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                continue;
            }
            if (nums[i] == nums[i - 1] + 1)
            {
                currentSteak++;
            }
            else
            {
                longest = max(longest, currentSteak);
                currentSteak = 1;
            }
        }
        return max(longest, currentSteak);
    }
};
// @lc code=end
