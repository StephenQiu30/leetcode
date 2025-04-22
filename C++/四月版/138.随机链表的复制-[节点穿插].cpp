/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制 [节点穿插]
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
        {
            return nullptr;
        }
        unordered_map<Node *, Node *> map;
        // 第一步：插入新节点
        Node *current = head;
        while (current)
        {
            Node *copy = new Node(current->val);
            copy->next = current->next;
            current->next = copy;
            copy = current->next;
        }
        current = head;
        // 第二步：复制random指针
        while (current)
        {
            if (current->random)
            {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }
        // 第三步：拆分链表
        Node *dummy = new Node(0);
        Node *copyCurr = dummy;
        current = head;
        while (current)
        {
            Node *copy = current->next;
            copyCurr->next = copy;
            current->next = copy->next;

            copyCurr = copy;
            current = current->next;
        }

        return dummy->next;
    }
};
// @lc code=end
