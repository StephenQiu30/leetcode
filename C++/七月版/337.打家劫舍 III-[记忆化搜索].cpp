/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III [记忆化搜索]
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
    unordered_map<TreeNode *, int> memo;
    int rob(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        if (memo.count(root))
        {
            return memo[root];
        }
        int do_int = root->val;
        if (root->left)
        {
            do_int += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right)
        {
            do_int += rob(root->right->left) + rob(root->right->right);
        }
        int not_do = rob(root->left) + rob(root->right);
        return memo[root] = max(do_int, not_do);
    }
};
// @lc code=end
