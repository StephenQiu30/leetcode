/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II [快慢指针]
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (slow == fast)
        {
            ListNode *ptr = head;
            while (ptr != slow)
            {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
        return nullptr;
    }
};
// @lc code=end
