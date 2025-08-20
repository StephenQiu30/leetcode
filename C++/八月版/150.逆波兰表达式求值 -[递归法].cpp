/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值 [递归法]
 */

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int index = tokens.size() - 1;
        return eval(tokens, index);
    }

    int eval(vector<string> &tokens, int &index)
    {
        string t = tokens[index--];
        if (t != "+" && t != "-" && t != "*" && t != "/")
        {
            return stoi(t);
        }
        int right = eval(tokens, index);
        int left = eval(tokens, index);
        if (t == "+")
        {
            return left + right;
        }
        if (t == "-")
        {
            return left - right;
        }
        if (t == "*")
        {
            return left * right;
        }
        return left / right;
    }
};
// @lc code=end
