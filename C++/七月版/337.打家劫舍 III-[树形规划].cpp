/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III [树形规划]
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
    int rob(TreeNode *root)
    {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
    pair<int, int> dfs(TreeNode *root)
    {
        if (!root)
        {
            return {0, 0};
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int notRob = max(left.first, left.second) + max(right.first, right.second);
        int rob = root->val + left.first + right.first;
        return {notRob, rob};
    }
};
// @lc code=end
