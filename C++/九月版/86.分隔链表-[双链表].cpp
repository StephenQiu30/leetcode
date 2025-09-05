/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表 [双链表]
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode dummyL(0), dummyG(0);
        ListNode *l = &dummyL, *g = &dummyG;
        ListNode *current = head;
        while (current)
        {
            if (current->val < x)
            {
                l->next = current;
                l = l->next;
            }
            else
            {
                g->next = current;
                g = g->next;
            }
            current = current->next;
        }
        // 结束 greater 链，避免环
        g->next = nullptr;
        // 连接两段
        l->next = dummyG.next;
        return dummyL.next;
    }
};
// @lc code=end
