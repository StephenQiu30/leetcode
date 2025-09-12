/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素 [递归]
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        // 递归处理后半部分
        head->next = deleteDuplicates(head->next);
        if (head->next && head->val == head->next->val)
        {
            // 舍弃 head，返回后面的唯一节点（或链）
            return head->next;
        }
        else
        {
            return head;
        }
    }
};
// @lc code=end
