/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列 [哈希表法]
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for (int num : nums)
        {
            if (!numSet.count(num - 1))
            {
                int currentNum = num;
                int currentStreak = 1;
                while (numSet.count(currentNum + 1))
                {
                    currentNum++;
                    currentStreak++;
                }
                longest = max(longest, currentStreak);
            }
        }
        return longest;
    }
};
// @lc code=end
