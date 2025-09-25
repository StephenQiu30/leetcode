/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和 [DFS]
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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int sum = 0;
        // 如果存在左子节点并且左子节点是叶子，则加上它的值
        if (root->left && !root->left->left && !root->left->right)
        {
            sum += root->left->val;
        }
        else
        {
            // 否则递归左子树
            sum += sumOfLeftLeaves(root->left);
        }
        // 右子树继续递归（右子节点即使是叶子也不计入，因为不是左叶）
        sum += sumOfLeftLeaves(root->right);
        return sum;
    }
};
// @lc code=end
