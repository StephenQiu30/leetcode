/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数 [比较法]
 */

// @lc code=start
class Solution
{
public:
    static bool cmpNoAlloc(const string &a, const string &b)
    {
        int na = a.size(), nb = b.size();
        int total = na + nb;
        for (int t = 0; t < total; ++t)
        {
            // 相当于 a + b
            char ca = (t < na) ? a[t] : b[t - na];
            // 相当于 b + a
            char cb = (t < nb) ? b[t] : a[t - nb];
            if (ca != cb)
            {
                return ca > cb;
            }
        }
        // 完全相等时不交换（等价）
        return false;
    }
    string largestNumber(vector<int> &nums)
    {
        vector<string> s;
        for (int x : nums)
        {
            s.push_back(to_string(x));
        }
        sort(s.begin(), s.end(), cmpNoAlloc);
        if (!s.empty() && s[0] == "0")
        {
            return "0";
        }
        string ans;
        for (auto &t : s)
        {
            ans += t;
        }
        return ans;
    }
};
// @lc code=end
