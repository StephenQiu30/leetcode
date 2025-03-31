/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间 [贪心算法]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();
        // 1. 添加所有在 newInterval 左侧且无重叠的区间
        while (i < n && intervals[i][1] < newInterval[0])
        {
            result.push_back(intervals[i]);
            i++;
        }
        // 2. 合并所有与 newInterval 重叠的区间
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        // 添加合并后的 newInterval
        result.push_back(newInterval);
        // 3. 添加所有在 newInterval 右侧的区间
        while (i < n)
        {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
// @lc code=end
