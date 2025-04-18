/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点 [暴力法]
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int length = 0;
        ListNode *current = head;
        while (current)
        {
            length++;
            current = current->next;
        }
        if (n == length)
        {
            return head->next;
        }
        current = head;
        for (int i = 1; i < length - n; i++)
        {
            current = current->next;
        }
        current->next = current->next->next;
        return head;
    }
};
// @lc code=end
