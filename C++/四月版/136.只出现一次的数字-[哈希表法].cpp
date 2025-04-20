/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字 [哈希表法]
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> count;
        for (int num : nums)
        {
            count[num]++;
        }
        for (auto &pair : count)
        {
            if (pair.second == 1)
            {
                return pair.first;
            }
        }
        return -1;
    }
};
// @lc code=end
