/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径 [DFS]
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
    int maxDiameter = 0;
    int diameterOfBinaryTree(TreeNode *root)
    {
        dfs(root);
        return maxDiameter;
    }

private:
    int dfs(TreeNode *node)
    {
        if (!node)
        {
            return 0;
        }
        int leftDepth = dfs(node->left);
        int rightDepth = dfs(node->right);
        maxDiameter = max(maxDiameter, leftDepth + rightDepth);
        // 返回以当前节点为根的最大深度
        return max(leftDepth, rightDepth) + 1;
    }
};
// @lc code=end
