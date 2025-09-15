/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径 [递归]
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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        if (!root)
        {
            return res;
        }
        dfs(root, "", res);
        return res;
    }

private:
    void dfs(TreeNode *node, string path, vector<string> &res)
    {
        if (!node)
        {
            return;
        }
        if (!path.empty())
        {
            path += "->";
        }
        path += to_string(node->val);
        if (!node->left && !node->right)
        {
            res.push_back(path);
            return;
        }
        dfs(node->left, path, res);
        dfs(node->right, path, res);
    }
};
// @lc code=end
