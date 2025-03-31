/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点 [迭代法]
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
        // 先创建一个虚拟头节点
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *current = dummy;
        // 需要确保当前节点的下一节点和下下节点是存在的
        while (current->next && current->next->next)
        {
            // 获取当前的两对节点
            ListNode *first = current->next;
            ListNode *second = current->next->next;

            // 进行节点交换
            first->next = second->next;
            second->next = first;
            current->next = second;

            // 移动当前指针到下一对节点
            current = first;
        }
        // 返回交换之后的链表头
        return dummy->next;
    }
};
// @lc code=end
