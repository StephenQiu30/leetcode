/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器 [惰性展开]
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
    using It = vector<NestedInteger>::const_iterator;
    stack<pair<It, It>> st;
    // 让栈顶迭代器指向一个整数；若做不到则清空栈
    void makeTopInteger()
    {
        while (!st.empty())
        {
            auto &top = st.top();
            // 当前层用尽，回到上一层
            if (top.first == top.second)
            {
                st.pop();
                continue;
            }
            if (top.first->isInteger())
            {
                // 栈顶就是整数，停
                return;
            }
            // 栈顶是列表：下钻一层
            const auto &lst = top.first->getList();
            // 先前进，再压入子层
            ++top.first;
            st.emplace(lst.begin(), lst.end());
        }
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        st.emplace(nestedList.begin(), nestedList.end());
        makeTopInteger();
    }

    int next()
    {
        // 调用前应确保 hasNext() == true
        int val = st.top().first->getInteger();
        // 消费这个整数
        ++st.top().first;
        // 维持栈顶为整数
        makeTopInteger();
        return val;
    }

    bool hasNext()
    {
        makeTopInteger();
        return !st.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end
