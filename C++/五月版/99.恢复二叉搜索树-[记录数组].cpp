/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树 [记录数组]
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        vector<TreeNode *> nodes;
        inorder(root, nodes);
        TreeNode *x = nullptr;
        TreeNode *y = nullptr;
        for (int i = 0; i < nodes.size() - 1; i++)
        {
            if (nodes[i]->val > nodes[i + 1]->val)
            {
                y = nodes[i + 1];
                if (x == nullptr)
                {
                    x = nodes[i];
                }
                else
                {
                    break;
                }
            }
        }
        swap(x->val, y->val);
    }
    void inorder(TreeNode *node, vector<TreeNode *> &nodes)
    {
        if (!node)
        {
            return;
        }
        inorder(node->left, nodes);
        nodes.push_back(node);
        inorder(node->right, nodes);
    }
};
// @lc code=end
