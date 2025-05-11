/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树 [迭代]
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty())
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode *> stack;
        stack.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); i++)
        {
            int val = preorder[i];
            TreeNode *node = stack.top();
            if (node->val != inorder[inorderIndex])
            {
                node->left = new TreeNode(val);
                stack.push(node->left);
            }
            else
            {
                while (!stack.empty() && stack.top()->val == inorder[inorderIndex])
                {
                    node = stack.top();
                    stack.pop();
                    inorderIndex++;
                }
                node->right = new TreeNode(val);
                stack.push(node->right);
            }
        }
        return root;
    }
};
// @lc code=end
