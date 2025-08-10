/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表 [优先队列]
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto cmp = [](ListNode *a, ListNode *b)
        {
            // 小顶堆
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)>
            pq(cmp);
        for (ListNode *node : lists)
        {
            if (node)
            {
                pq.push(node);
            }
        }
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while (!pq.empty())
        {
            ListNode *current = pq.top();
            pq.pop();
            tail->next = current;
            tail = tail->next;
            if (current->next)
            {
                pq.push(current->next);
            }
        }
        // 确保链表结束（通常不必须，但保险起见）
        tail->next = nullptr;
        return dummy.next;
    }
};
// @lc code=end
