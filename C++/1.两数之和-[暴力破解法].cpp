/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和 [暴力破解法]
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 先获取数组的长度
        int n = nums.size();
        // 遍历数组
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                // 比较数组中两个元素的值和目标值
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
// @lc code=end