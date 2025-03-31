/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间 [双指针]
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
        int i = 0, n = intervals.size();
        while (i < n)
        {
            int start = intervals[i][0], end = intervals[i][1];
            int j = i + 1;
            // 用 j 指针寻找可以合并的区间
            while (j < n && intervals[j][0] <= end)
            {
                // 扩展终点
                end = max(end, intervals[j][1]);
                j++;
            }
            // 记录合并后的区间
            result.push_back({start, end});
            // 移动 i 指向下一个未合并的区间
            i = j;
        }

        return result;
    }
};
// @lc code=end
