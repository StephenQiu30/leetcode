/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏 [倒推法]
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int lastPops = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (i + nums[i] >= lastPops)
            {
                lastPops = i;
            }
        }
        return lastPops == 0;
    }
};
// @lc code=end
