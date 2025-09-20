/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树 [递归]
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        if (n == 0)
        {
            return nullptr;
        }
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++)
        {
            index[inorder[i]] = i;
        }
        int post_index = n - 1;
        return build(0, n - 1, inorder, postorder, post_index, index);
    }

private:
    TreeNode *build(int left, int right, vector<int> &inorder, vector<int> &postorder, int &post_index, unordered_map<int, int> &index)
    {
        if (left > right)
        {
            return nullptr;
        }
        int root_value = postorder[post_index--];
        TreeNode *root = new TreeNode(root_value);
        int in_root_index = index[root_value];
        root->right = build(in_root_index + 1, right, inorder, postorder, post_index, index);
        root->left = build(left, in_root_index - 1, inorder, postorder, post_index, index);
        return root;
    }
};
// @lc code=end
