/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素 [二叉搜索树 + 维护子树大小]
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
    int kthSmallest(TreeNode *root, int k)
    {
        int leftSize = countNodes(root->left);
        if (leftSize + 1 == k)
        {
            return root->val;
        }
        if (leftSize + 1 > k)
        {
            return kthSmallest(root->left, k);
        }
        return kthSmallest(root->right, k - leftSize - 1);
    }

private:
    int countNodes(TreeNode *node)
    {
        // 递归调用终止条件
        if (!node)
        {
            return 0;
        }
        return 1 + countNodes(node->left) + countNodes(node->right);
    }
};
// @lc code=end
