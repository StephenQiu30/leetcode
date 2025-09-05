/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表 [原地交换]
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
        if (!head)
        {
            return nullptr;
        }
        ListNode *i = head, *j = head;
        while (j)
        {
            if (j->val < x)
            {
                int temp = i->val;
                i->val = j->val;
                j->val = temp;
                i = i->next;
            }
            j = j->next;
        }
        return head;
    }
};
// @lc code=end
