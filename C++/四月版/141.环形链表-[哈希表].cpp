/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表 [哈希表]
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
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> visted;
        while (head)
        {
            if (visted.count(head))
            {
                return true;
            }
            visted.insert(head);
            head = head->next;
        }
        return false;
    }
};
// @lc code=end
