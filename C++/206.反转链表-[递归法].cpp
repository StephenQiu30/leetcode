/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表 [递归法]
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
    ListNode *reverseList(ListNode *head)
    {
        // 终止条件，返回新头节点
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *prev = reverseList(head->next);
        // 反转当前节点
        head->next->next = head;
        // 断开原来的连接，防止环形链表
        head->next = nullptr;
        // 返回新的头节点
        return prev;
    }
};
// @lc code=end
