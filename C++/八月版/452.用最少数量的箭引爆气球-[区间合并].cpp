/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球 [区间合并]
 */

// @lc code=start
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.empty())
        {
            return 0;
        }
        sort(points.begin(), points.end());
        int arrows = 1;
        long long right = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] <= right)
            {
                right = min((long long)points[i][1], right);
            }
            else
            {
                arrows++;
                right = points[i][1];
            }
        }
        return arrows;
    }
};
// @lc code=end
