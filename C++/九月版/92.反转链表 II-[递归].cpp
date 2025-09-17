/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II [递归]
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
    // 用于连接反转后的链表
    ListNode *successor = nullptr;

public:
    ListNode *reverseN(ListNode *head, int n)
    {
        if (n == 1)
        {
            successor = head->next;
            return head;
        }
        ListNode *last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return last;
    }
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == 1)
        {
            return reverseN(head, right);
        }
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
};
// @lc code=end
