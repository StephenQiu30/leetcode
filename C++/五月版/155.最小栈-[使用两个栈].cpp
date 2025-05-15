/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈 [使用两个栈]
 */

// @lc code=start
class MinStack
{
private:
    stack<int> dataStack;
    stack<int> minStack;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        dataStack.push(val);
        if (minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
        else
        {
            minStack.push(minStack.top());
        }
    }

    void pop()
    {
        dataStack.pop();
        minStack.pop();
    }

    int top()
    {
        return dataStack.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
