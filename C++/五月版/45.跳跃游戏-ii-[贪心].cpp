/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II [贪心]
 */

// @lc code=start
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int jumps = 0;
        int currentEnd = 0, currentFarthest = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            currentFarthest = max(currentFarthest, i + nums[i]);
            if (i == currentEnd)
            {
                jumps++;
                currentEnd = currentFarthest;
            }
        }
        return jumps;
    }
};
// @lc code=end
