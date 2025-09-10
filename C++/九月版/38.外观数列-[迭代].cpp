/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列 [迭代]
 */

// @lc code=start
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n <= 0)
        {
            return "";
        }
        string s = "1";
        for (int i = 2; i <= n; i++)
        {
            string t;
            // 经验上下一项长度不会小于当前项，预分配可减少重分配
            t.reserve(s.size() * 2);
            int count = 1;
            for (int j = 1; j < s.size(); j++)
            {
                if (s[j] == s[j - 1])
                {
                    count++;
                }
                else
                {
                    t += to_string(count);
                    t.push_back(s[j - 1]);
                    count = 1;
                }
            }
            // 处理最后一组
            t += to_string(count);
            t.push_back(s.back());
            s.swap(t);
        }
        return s;
    }
};
// @lc code=end
