/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III [dfs]
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
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return 0;
        }
        return dfs(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

private:
    int dfs(TreeNode *node, long long target)
    {
        if (!node)
        {
            return 0;
        }
        int count = 0;
        if (node->val == target)
        {
            count++;
        }
        count += dfs(node->left, target - node->val);
        count += dfs(node->right, target - node->val);
        return count;
    }
};
// @lc code=end
