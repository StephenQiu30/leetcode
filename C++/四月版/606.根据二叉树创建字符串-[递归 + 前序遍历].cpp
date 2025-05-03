/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串 [递归 + 前序遍历]
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
    string tree2str(TreeNode *root)
    {
        if (!root)
        {
            return "";
        }
        string res = to_string(root->val);
        if (root->left || root->right)
        {
            res += "(" + tree2str(root->left) + ")";
        }
        if (root->right)
        {
            res += "(" + tree2str(root->right) + ")";
        }
        return res;
    }
};
// @lc code=end
