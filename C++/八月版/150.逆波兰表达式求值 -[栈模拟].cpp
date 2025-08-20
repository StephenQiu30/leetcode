/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值 [栈模拟]
 */

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (auto &t : tokens)
        {
            if (t == "+" || t == "-" || t == "*" || t == "/")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if (t == "+")
                {
                    st.push(a + b);
                }
                else if (t == "-")
                {
                    st.push(a - b);
                }
                else if (t == "*")
                {
                    st.push(a * b);
                }
                else
                {
                    st.push(a / b);
                }
            }
            else
            {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};
// @lc code=end
