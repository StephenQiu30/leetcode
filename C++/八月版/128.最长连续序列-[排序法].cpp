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
        sort(nums.begin(), nums.end());
        int longset = 1, currentLength = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                continue;
            }
            if (nums[i] == nums[i - 1] + 1)
            {
                currentLength++;
            }
            else
            {
                longset = max(longset, currentLength);
                currentLength = 1;
            }
        }
        return max(longset, currentLength);
    }
};
// @lc code=end
