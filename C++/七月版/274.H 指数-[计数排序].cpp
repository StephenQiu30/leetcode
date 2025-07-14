/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数 [计数排序]
 */

// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        vector<int> buckets(n + 1, 0);
        for (int citation : citations)
        {
            if (citation >= n)
            {
                buckets[n]++;
            }
            else
            {
                buckets[citation]++;
            }
        }
        int total = 0;
        for (int i = n; i >= 0; i--)
        {
            total += buckets[i];
            if (total >= i)
            {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end
