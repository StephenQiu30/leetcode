/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级 [分治法]
 */

// @lc code=start
class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        return compute(expression);
    }

private:
    vector<int> compute(const string &s)
    {
        vector<int> res;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            char c = s[i];
            if (c == '+' || c == '-' || c == '*')
            {
                vector<int> left = compute(s.substr(0, i));
                vector<int> right = compute(s.substr(i + 1));
                for (int a : left)
                {
                    for (int b : right)
                    {
                        if (c == '+')
                        {
                            res.push_back(a + b);
                        }
                        else if (c == '-')
                        {
                            res.push_back(a - b);
                        }
                        else if (c == '*')
                        {
                            res.push_back(a * b);
                        }
                    }
                }
            }
        }
        // 如果没有运算符，整个 s 就是一个数字
        if (res.empty())
        {
            res.push_back(stoi(s));
        }
        return res;
    }
};
// @lc code=end
