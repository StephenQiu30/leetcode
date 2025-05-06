/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        int n = s.size(), m = p.size();
        if (n < m)
        {
            return res;
        }
        string sortedP = p;
        sort(sortedP.begin(), sortedP.end());
        for (int i = 0; i <= n - m; i++)
        {
            string sub = s.substr(i, m);
            sort(sub.begin(), sub.end());
            if (sub == sortedP)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end
