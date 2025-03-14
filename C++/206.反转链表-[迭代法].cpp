/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表 [迭代法]
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
    ListNode *reverseList(ListNode *head)
    {
        // 人之初生，过去为空，现在从头，未来不存
        ListNode *prev = nullptr;
        ListNode *current = head;
        while (current)
        {
            // 未来出于现在
            ListNode *next = current->next;
            // 现在指向过去
            current->next = prev;
            // 过去成为现在
            prev = current;
            // 现在成为未来
            current = next;
        }
        // 生之将亡，唯过去返回彼岸
        return prev;
    }
};
// @lc code=end
