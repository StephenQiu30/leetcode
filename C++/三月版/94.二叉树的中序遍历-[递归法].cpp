/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历 [递归法]
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        inOrder(root, result);
        return result;
    }

private:
    void inOrder(TreeNode *root, vector<int> &result)
    {
        if (root == nullptr)
        {
            return;
        }

        inOrder(root->left, result);
        result.push_back(root->val);
        inOrder(root->right, result);
    }
};
// @lc code=end
