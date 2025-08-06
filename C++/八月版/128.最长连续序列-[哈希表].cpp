/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列 [哈希表]
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        int longset = 0;
        for (int num : s)
        {
            if (!s.count(num - 1))
            {
                int current = num;
                int streak = 1;
                while (s.count(current + 1))
                {
                    current++;
                    streak++;
                }
                longset = max(longset, streak);
            }
        }
        return longset;
    }
};
// @lc code=end
