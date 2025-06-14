/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水 [双指针法]
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0, res = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (height[left] >= leftMax)
                {
                    leftMax = height[left];
                }
                else
                {
                    res += leftMax - height[left];
                }
                ++left;
            }
            else
            {
                if (height[right] >= rightMax)
                {
                    rightMax = height[right];
                }
                else
                {
                    res += rightMax - height[right];
                }
                --right;
            }
        }
        return res;
    }
};
// @lc code=end
