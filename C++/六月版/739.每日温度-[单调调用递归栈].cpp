/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度 [单调调用递归栈]
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> stack;
        for (int i = 0; i < n; i++)
        {
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()])
            {
                int prevIndex = stack.top();
                stack.pop();
                answer[prevIndex] = i - prevIndex;
            }
            stack.push(i);
        }
        return answer;
    }
};
// @lc code=end
