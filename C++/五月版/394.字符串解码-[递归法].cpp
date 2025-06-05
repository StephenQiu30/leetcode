/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码 [迭代法]
 */

// @lc code=start
class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> numStack;
        stack<string> strStack;
        string currentStr = "";
        int num = 0;

        for (char c : s)
        {
            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            else if (c == '[')
            {
                numStack.push(num);
                strStack.push(currentStr);
                num = 0;
                currentStr = "";
            }
            else if (c == ']')
            {
                int repeat = numStack.top();
                numStack.pop();
                string prevStr = strStack.top();
                strStack.pop();
                while (repeat--)
                {
                    prevStr += currentStr;
                }
                currentStr = prevStr;
            }
            else
            {
                currentStr += c;
            }
        }
        return currentStr;
    }
};
// @lc code=end
