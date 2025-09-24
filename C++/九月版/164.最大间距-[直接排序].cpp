/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距 [直接排序]
 */

// @lc code=start
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};
// @lc code=end
