/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树 [常量空间]
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
    TreeNode *x = nullptr, *y = nullptr, *pre = nullptr;
    void recoverTree(TreeNode *root)
    {
        inorder(root);
        swap(x->val, y->val);
    }
    void inorder(TreeNode *node)
    {
        if (!node)
        {
            return;
        }
        inorder(node->left);
        if (pre && pre->val > node->val)
        {
            if (!x)
            {
                x = pre;
            }
            y = node;
        }
        pre = node;
        inorder(node->right);
    }
};
// @lc code=end
