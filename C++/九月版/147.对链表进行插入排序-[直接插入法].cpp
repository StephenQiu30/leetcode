/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序 [直接插入法]
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
        // 哨兵
        ListNode *dummy = new ListNode(0);
        ListNode *current = head;
        while (current)
        {
            // 保存下一个节点
            ListNode *next = current->next;
            // 找到插入位置（保持稳定：相等值在前）
            ListNode *prev = dummy;
            while (prev->next && prev->next->val <= current->val)
            {
                prev = prev->next;
            }
            // 插入 cur 到 prev 之后
            current->next = prev->next;
            prev->next = current;
            current = next;
        }
        return dummy->next;
    }
};
// @lc code=end
