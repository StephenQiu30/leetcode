/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表 [归并排序(迭代)]
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

        // 1. 获取链表长度
        int n = 0;
        ListNode *node = head;
        while (node)
        {
            n++;
            node = node->next;
        }

        ListNode dummy(0);
        dummy.next = head;
        // 2. 归并子链表的长度
        for (int size = 1; size < n; size <<= 1)
        {
            ListNode *cur = dummy.next;
            ListNode *tail = &dummy;

            while (cur)
            {
                ListNode *left = cur;
                ListNode *right = split(left, size); // 分割出右链表
                cur = split(right, size);            // 剩下的下一组
                tail = merge(left, right, tail);     // 合并两组
            }
        }

        return dummy.next;
    }

private:
    // 将链表head切成前n个节点，返回后面部分的头节点
    ListNode *split(ListNode *head, int n)
    {
        while (--n && head)
        {
            head = head->next;
        }
        if (!head)
            return nullptr;
        ListNode *second = head->next;
        head->next = nullptr;
        return second;
    }

    // 合并l1和l2，然后接到tail后，返回新的tail
    ListNode *merge(ListNode *l1, ListNode *l2, ListNode *tail)
    {
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

        while (tail->next)
            tail = tail->next; // 移到链表末尾
        return tail;
    }
};
// @lc code=end
