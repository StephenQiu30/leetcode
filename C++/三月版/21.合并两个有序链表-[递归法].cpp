/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表 [递归法]
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 创建一个虚拟节点 dummy 和一个 current 指针，初始化为虚拟节点。
        ListNode *dummy = new ListNode(-1);
        ListNode *current = dummy;
        // 使用 while 循环遍历两个链表，直到其中一个链表为空
        while (list1 != nullptr && list2 != nullptr)
        {
            // 比较两个链表当前节点的值，选择较小的节点接入到 current 的下一个节点。
            if (list1->val < list2->val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }
            // 移动当前链表指针到下一个节点。
            current = current->next;
        }
        // 将未处理完的链表连接到 current 的下一个节点。
        // 处理剩余节点
        if (list1 != nullptr)
        {
            current->next = list1;
        }
        else
        {
            current->next = list2;
        }

        // 返回合并后的链表
        return dummy->next;
    }
};
// @lc code=end
