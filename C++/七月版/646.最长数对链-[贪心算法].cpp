/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链 [贪心算法]
 */

// @lc code=start
class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });
        int res = 0, current = INT_MIN;
        for (auto &pair : pairs)
        {
            if (pair[0] > current)
            {
                ++res;
                current = pair[1];
            }
        }
        return res;
    }
};
// @lc code=end
