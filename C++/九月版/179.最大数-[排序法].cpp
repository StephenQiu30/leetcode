/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数 [排序法]
 */

// @lc code=start
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> s;
        s.reserve(nums.size());
        for (int x : nums)
        {
            s.push_back(to_string(x));
        }
        sort(s.begin(), s.end(), [](const string &a, const string &b)
             { return a + b > b + a; });
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
