/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表 [分支合并]
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
    ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while (a && b)
        {
            if (a->val < b->val)
            {
                tail->next = a;
                a = a->next;
            }
            else
            {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return dummy.next;
    }
    ListNode *mergeRange(vector<ListNode *> &lists, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        if (left == right)
        {
            return lists[left];
        }
        int mid = left + (right - left) / 2;
        ListNode *l = mergeRange(lists, left, mid);
        ListNode *r = mergeRange(lists, mid + 1, right);
        return mergeTwoLists(l, r);
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
        {
            return nullptr;
        }
        return mergeRange(lists, 0, (int)lists.size() - 1);
    }
};
// @lc code=end
