/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和 [分治法]
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
    pair<int, int> helper(TreeNode *node)
    {
        if (!node)
        {
            return {INT_MIN, 0};
        }
        auto L = helper(node->left);
        auto R = helper(node->right);

        int leftMaxSub = L.first, leftDown = L.second;
        int rightMaxSub = R.first, rightDown = R.second;

        int maxDown = max(node->val, node->val + max(leftDown, rightDown));
        int throughNode = node->val + max(0, leftDown) + max(0, rightDown);

        int maxSub = max({leftMaxSub, rightMaxSub, throughNode, maxDown});
        return {maxSub, maxDown};
    }
    int maxPathSum(TreeNode *root)
    {
        return helper(root).first;
    }
};
// @lc code=end
