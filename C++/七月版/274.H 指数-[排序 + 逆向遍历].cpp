/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数 [排序 + 逆向遍历]
 */

// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        // 降序排序
        sort(citations.rbegin(), citations.rend());
        int h = 0;
        for (int i = 0; i < citations.size(); i++)
        {
            if (citations[i] >= i + 1)
            {
                h = i + 1;
            }
            else
            {
                break;
            }
        }
        return h;
    }
};
// @lc code=end
