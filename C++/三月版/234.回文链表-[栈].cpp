/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表 [栈]
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<int> st;
        ListNode *temp = head;
        // 1. 遍历链表并存入栈
        while (temp)
        {
            st.push(temp->val);
            temp = temp->next;
        }
        // 2. 再次遍历链表，与栈顶元素比较
        temp = head;
        while (temp)
        {
            if (temp->val != st.top())
            {
                return false;
            }
            st.pop();
            temp = temp->next;
        }
        return true;
    }
};

// @lc code=end
