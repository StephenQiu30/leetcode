/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
        {
            return 0;
        }
        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i)
        {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        int res = 0;
        for (int i = 1; i < n - 1; ++i)
        {
            res += min(leftMax[i], rightMax[i]) - height[i];
        }

        return res;
    }
};
// @lc code=end
