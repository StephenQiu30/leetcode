/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表 [哈希表]
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> visited;
        while (headA)
        {
            visited.insert(headA);
            headA = headA->next;
        }
        while (headB)
        {
            if (visited.count(headB))
            {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};
// @lc code=end
