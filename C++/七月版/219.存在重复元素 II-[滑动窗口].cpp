/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II [滑动窗口]
 */

// @lc code=start
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> window;
        for (int i = 0; i < nums.size(); i++)
        {
            if (window.count(nums[i]))
            {
                return true;
            }
            window.insert(nums[i]);
            if (window.size() > k)
            {
                window.erase(nums[i - k]);
            }
        }
        return false;
    }
};
// @lc code=end
