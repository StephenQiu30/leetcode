/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表 [快慢指针]
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
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
        {
            return true;
        }
        // 使用快慢指针找到链表的中点
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 反转后半部分链表
        ListNode *secondHalf = reverseList(slow);
        // 比较前半部分和后半部分
        ListNode *firstHalf = head;
        ListNode *temp = secondHalf;
        while (temp)
        {
            if (firstHalf->val != temp->val)
            {
                return false;
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }
        return true;
    }

private:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        while (head)
        {
            ListNode *nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }
};
// @lc code=end
