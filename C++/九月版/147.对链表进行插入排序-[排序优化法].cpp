/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序 [排序优化法]
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
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        // 哨兵
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *lastSorted = head;
        ListNode *current = head->next;
        while (current)
        {
            if (lastSorted->val <= current->val)
            {
                // cur 已经在正确位置
                lastSorted = current;
            }
            else
            {
                // 需要在已排序区间中找到插入位置
                ListNode *prev = dummy;
                while (prev->next && prev->next->val <= current->val)
                {
                    prev = prev->next;
                }
                // 切出 cur 并插入到 prev 之后
                lastSorted->next = current->next;
                current->next = prev->next;
                prev->next = current;
            }
            current = lastSorted->next;
        }
        return dummy->next;
    }
};
// @lc code=end
