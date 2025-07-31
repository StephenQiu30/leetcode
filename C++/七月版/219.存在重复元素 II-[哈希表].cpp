/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II [哈希表]
 */

// @lc code=start
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.count(nums[i]) && i - map[nums[i]] <= k)
            {
                return true;
            }
            map[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end
