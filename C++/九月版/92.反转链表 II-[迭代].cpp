/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II [迭代]
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || left == right)
        {
            return head;
        }
        ListNode dummy(0, head);
        ListNode *prev = &dummy;
        // 移动 prev 到 left 的前一个节点
        for (int i = 1; i < left; i++)
        {
            prev = prev->next;
        }
        ListNode *current = prev->next;
        // 进行头插法反转
        for (int i = 0; i < right - left; i++)
        {
            ListNode *temp = current->next;
            current->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        return dummy.next;
    }
};
// @lc code=end
