/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点 [快慢指针]
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
        ListNode *dummy = new ListNode(0, head);
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        // fast 先走 n + 1步
        for (int i = 0; i <= n; i++)
        {
            fast = fast->next;
        }
        // fast 和 slow 一起走，知道 fast 到达末尾
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // 删除 slow->next
        slow->next = slow->next->next;
        return dummy->next;
    }
};
// @lc code=end
