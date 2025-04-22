/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制 [哈希表]
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
        Node *current = head;
        // 第一次遍历，创建新节点
        while (current)
        {
            map[current] = new Node(current->val);
            current = current->next;
        }
        current = head;
        // 第二次遍历，设置next和random
        while (current)
        {
            map[current]->next = map[current->next];
            map[current]->random = map[current->random];
            current = current->next;
        }
        return map[head];
    }
};
// @lc code=end
