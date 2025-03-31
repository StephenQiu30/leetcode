/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素 [集合法]
 */

// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> map;
        for (int num : nums)
        {
            if (map.count(num))
            {
                return true;
            }
            map.insert(num);
        }
        return false;
    }
};
// @lc code=end
