/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加 [递归法]
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return addTwoNumbersFunction(l1, l2, 0);
    }

private:
    ListNode *addTwoNumbersFunction(ListNode *l1, ListNode *l2, int carry)
    {
        // 如果l1和l2都为空且没有进位，递归结束
        if (!l1 && !l2 && carry == 0)
        {
            return nullptr;
        }
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;

        int sum = n1 + n2 + carry;
        // 创建当前节点位置
        ListNode *currentNode = new ListNode(sum % 10);
        // 当前进位
        int newCarry = sum / 10;
        // 递归调用处理剩余的节点，并将当前节点的next指向递归返回的结果
        currentNode->next = addTwoNumbersFunction(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, newCarry);

        return currentNode;
    }
};

// @lc code=end
