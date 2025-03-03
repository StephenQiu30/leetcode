/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间 [排序法]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // 先对集合进行排序
        if (intervals.empty())
        {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        // 创建一个结果集合用来接收合并区间之后的结果
        vector<vector<int>> result;
        for (const auto &interval : intervals)
        {
            if (result.empty() || result.back()[1] < interval[0])
            {
                result.push_back(interval);
            }
            else
            {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};
// @lc code=end
