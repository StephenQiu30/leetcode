/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        if (n % 2 == 1)
        {
            return false;
        }
        // 创建一个哈希表用于存储括号匹配规则
        unordered_map<char, char> parisMap = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        // 创建一个无序空栈
        stack<char> validateStack;
        // 遍历字符串
        for (char c : s)
        {
            // 如果是左括号检查栈顶元素
            if (parisMap.count(c))
            {
                // 如果栈为空说明没有匹配的左括号
                if (validateStack.empty() || validateStack.top() != parisMap[c])
                {
                    return false;
                }
                // 匹配成功的话就弹出栈顶元素
                validateStack.pop();
            }
            else
            {
                // 如果是左括号就压入栈中
                validateStack.push(c);
            }
        }
        // 如果最后栈为空则说明所有括号都匹配成功了
        return validateStack.empty();
    }
};
// @lc code=end
