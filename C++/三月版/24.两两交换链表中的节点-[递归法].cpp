/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点 [递归法]
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
    ListNode *swapPairs(ListNode *head)
    {
        // 递归终止的条件: 链表中为空或者只有一个节点了
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        // 交换当前的两个节点
        ListNode *first = head;
        ListNode *second = head->next;

        // 递归处理剩下的节点
        first->next = swapPairs(second->next);
        second->next = first;

        // 返回新的头节点
        return second;
    }
};
// @lc code=end
