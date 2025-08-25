/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II [拉链法]
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
        {
            return root;
        }
        // 当前层起点
        Node *current = root;
        while (current)
        {
            // 下一层的虚拟头
            Node dummy(0);
            // 下一层的构建尾指针
            Node *tail = &dummy;
            for (Node *p = current; p; p = p->next)
            {
                if (p->left)
                {
                    tail->next = p->left;
                    tail = tail->next;
                }
                if (p->right)
                {
                    tail->next = p->right;
                    tail = tail->next;
                }
            }
            // 跳到下一层最左
            current = dummy.next;
        }
        return root;
    }
};
// @lc code=end
