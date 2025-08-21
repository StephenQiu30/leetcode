/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球 [贪心]
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
        sort(points.begin(), points.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; });
        int arrows = 1;
        long long pos = points[0][1];
        for (auto &p : points)
        {
            if (p[0] > pos)
            {
                arrows++;
                pos = p[1];
            }
        }
        return arrows;
    }
};
// @lc code=end
