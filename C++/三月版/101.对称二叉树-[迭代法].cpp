/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树 [迭代法]
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
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        queue<TreeNode *> queue;
        queue.push(root->left);
        queue.push(root->right);

        while (!queue.empty())
        {
            TreeNode *left = queue.front();
            queue.pop();
            TreeNode *right = queue.front();
            queue.pop();
            if (!left && !right)
            {
                continue;
            }
            if (!left || !right || left->val != right->val)
            {
                return false;
            }
            queue.push(left->left);
            queue.push(right->right);
            queue.push(left->right);
            queue.push(right->left);
        }
        return true;
    }
};
// @lc code=end
