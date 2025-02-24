/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成 [回溯法]
 */

// @lc code=start
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string> &result, string current, int left_count, int right_count, int n)
    {
        // 如果生成的字符串长度是需要生成长度的二倍则生成的长度是合法的
        int length = current.size();
        // 确保生成的长度是合法的
        if (length == n * 2)
        {
            // 让当前字符串入栈
            result.push_back(current);
            return;
        }
        // 如果左括号的数量小于 n 则可以继续加左括号
        if (left_count < n)
        {
            backtrack(result, current + '(', left_count + 1, right_count, n);
        }
        // 如果右括号的数量小于左括号的数量可以继续添加左括号
        if (right_count < left_count)
        {
            backtrack(result, current + ')', left_count, right_count + 1, n);
        }
    }
};
// @lc code=end
