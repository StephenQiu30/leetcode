/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间 [贪心算法]
 */

// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++)
        {
            // 记录每个字符最后一次出现的位置
            last[s[i] - 'a'] = i;
        }
        vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // 当前段最远边界
            end = max(end, last[s[i] - 'a']);
            // 到达边界，分段
            if (i == end)
            {
                res.push_back(end - start + 1);
                // 下一段开始
                start = i + 1;
            }
        }
        return res;
    }
};
// @lc code=end
