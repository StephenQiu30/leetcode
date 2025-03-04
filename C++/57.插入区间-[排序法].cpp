/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间 [排序法]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        // 1. 添加新区间
        intervals.push_back(newInterval);

        // 2. 排序，按区间起点排序
        sort(intervals.begin(), intervals.end());

        // 3. 进行合并
        vector<vector<int>> merged;
        for (const auto &interval : intervals)
        {
            if (merged.empty() || merged.back()[1] < interval[0])
            {
                merged.push_back(interval);
            }
            else
            {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};
// @lc code=end
