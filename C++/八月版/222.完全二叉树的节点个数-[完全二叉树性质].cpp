/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数 [完全二叉树性质]
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
    int countNodes(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int leftHeight = depth(root->left);
        int rightHeight = depth(root->right);
        if (leftHeight == rightHeight)
        {
            // 左子树满：节点数 = 2^lh（含根 + 左满树），剩下递归右子树
            return (1 << leftHeight) + countNodes(root->right);
        }
        else
        {
            // 右子树满：节点数 = 2^rh（含根 + 右满树），剩下递归左子树
            return (1 << rightHeight) + countNodes(root->left);
        }
    }

private:
    // 计算沿最左链的层数（根为1层）
    int depth(TreeNode *node)
    {
        int d = 0;
        while (node)
        {
            ++d;
            node = node->left;
        }
        return d;
    }
};
// @lc code=end
