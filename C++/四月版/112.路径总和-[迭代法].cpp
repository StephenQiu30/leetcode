/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和 [迭代法]
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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return false;
        }
        stack<TreeNode *> nodeStack;
        stack<int> sumStack;
        nodeStack.push(root);
        sumStack.push(root->val);
        while (!nodeStack.empty())
        {
            TreeNode *node = nodeStack.top();
            nodeStack.pop();
            int currentSum = sumStack.top();
            sumStack.pop();
            if (!node->left && !node->right && currentSum == targetSum)
            {
                return true;
            }
            if (node->right)
            {
                nodeStack.push(node->right);
                sumStack.push(currentSum + node->right->val);
            }
            if (node->left)
            {
                nodeStack.push(node->left);
                sumStack.push(currentSum + node->left->val);
            }
        }
        return false;
    }
};
// @lc code=end
