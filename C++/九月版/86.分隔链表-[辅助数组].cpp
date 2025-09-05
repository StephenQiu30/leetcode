/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表 [辅助数组]
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
        vector<ListNode *> small, big;
        ListNode *current = head;
        while (current)
        {
            if (current->val < x)
            {
                small.push_back(current);
            }
            else
            {
                big.push_back(current);
            }
            current = current->next;
        }
        vector<ListNode *> all;
        all.reserve(small.size() + big.size());
        for (auto p : small)
        {
            all.push_back(p);
        }
        for (auto p : big)
        {
            all.push_back(p);
        }
        if (all.empty())
        {
            return nullptr;
        }
        for (int i = 0; i < all.size() - 1; i++)
        {
            all[i]->next = all[i + 1];
        }
        all.back()->next = nullptr;
        return all.front();
    }
};
// @lc code=end
