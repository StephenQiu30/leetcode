/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串 [编码法]
 */

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        return transform(s) == transform(t);
    }
    vector<int> transform(const string &str)
    {
        unordered_map<char, int> index;
        vector<int> result;
        for (int i = 0; i < str.length(); i++)
        {
            if (!index.count(str[i]))
            {
                index[str[i]] = i;
            }
            result.push_back(index[str[i]]);
        }
        return result;
    }
};
// @lc code=end
