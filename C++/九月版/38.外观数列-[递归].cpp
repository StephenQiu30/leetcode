/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列 [递归]
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
        if (n == 1)
        {
            return "1";
        }
        string prev = countAndSay(n - 1);
        string current;
        current.reserve(prev.size() * 2);
        int count = 1;
        for (int i = 1; i < prev.size(); i++)
        {
            if (prev[i] == prev[i - 1])
            {
                count++;
            }
            else
            {
                current += to_string(count);
                current.push_back(prev[i - 1]);
                count = 1;
            }
        }
        current += to_string(count);
        current.push_back(prev.back());
        return current;
    }
};
// @lc code=end
