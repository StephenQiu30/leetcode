/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表 [归并排序(递归)]
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
    ListNode *sortList(ListNode *head)
    {
        // 基础情况：空链表或只有一个节点，已经有序
        if (!head || !head->next)
        {
            return head;
        }
        // 1. 使用快慢指针找到链表中点
        ListNode *slow = head;
        ListNode *fast = head->next;
        // 注意 fast 要先走一步，确保 slow 在中点左边
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        // 2. 断开链表，分成两半
        ListNode *mid = slow->next;
        slow->next = nullptr;
        // 3. 递归排序左右部分
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        // 4. 合并两个有序链表
        return merge(left, right);
    }

private:
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
// @lc code=end
