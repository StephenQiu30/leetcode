/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        for (int i = 0; i <= nums.size() - k; i++)
        {
            int maxValue = nums[i];
            for (int j = i; j < i + k; j++)
            {
                maxValue = max(maxValue, nums[j]);
            }
            res.push_back(maxValue);
        }
        return res;
    }
};
// @lc code=end
