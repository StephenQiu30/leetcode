/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素 [哈希表法]
 */

// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, bool> hashMap;
        for (int num : nums)
        {
            if (hashMap.count(num))
            {
                return true;
            }
            hashMap[num] = true;
        }
        return false;
    }
};
// @lc code=end
