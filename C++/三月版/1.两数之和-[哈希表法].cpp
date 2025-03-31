/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和 [哈希表法]
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 获取数组的长度
        int n = nums.size();
        unordered_map<int, int> hashtable;
        for (int i = 0; i < n; ++i)
        {
            auto item = hashtable.find(target - nums[i]);
            if (item != hashtable.end())
            {
                return {item->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end