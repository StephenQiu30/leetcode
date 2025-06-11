/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列 [贪心算法]
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> tail;
        for (int num : nums)
        {
            auto item = lower_bound(tail.begin(), tail.end(), num);
            if (item == tail.end())
            {
                tail.push_back(num);
            }
            else
            {
                *item = num;
            }
        }
        return tail.size();
    }
};
// @lc code=end
