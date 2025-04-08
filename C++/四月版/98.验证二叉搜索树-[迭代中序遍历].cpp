/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树 [迭代中序遍历]
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
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> stack;
        long long prev = LONG_LONG_MIN;
        while (root || !stack.empty())
        {
            while (root)
            {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if (root->val <= prev)
            {
                return false;
            }
            prev = root->val;
            root = root->right;
        }
        return true;
    }
};
// @lc code=end
