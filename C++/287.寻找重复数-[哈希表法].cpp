/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数 [哈希表法]
 */

// @lc code=start
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_set<int> seen;
        for (int num : nums)
        {
            if (seen.count(num))
            {
                // 找到重复数
                return num;
            }
            seen.insert(num);
        }
        return -1;
    }
};
// @lc code=end
