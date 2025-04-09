/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        int n = height.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int area = min(height[i], height[j]) * (j - i);
                max_area = max(max_area, area);
            }
        }
        return max_area;
    }
};
// @lc code=end
