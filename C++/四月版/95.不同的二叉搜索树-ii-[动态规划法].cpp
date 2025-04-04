/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II [动态规划]
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
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
        {
            return {};
        }
        vector<vector<TreeNode *>> dp(n + 1);
        dp[0] = {nullptr};
        for (int length = 1; length <= n; length++)
        {
            dp[length] = {};
            for (int root = 1; root <= length; root++)
            {
                int leftLen = root - 1;
                int rightLen = length - root;
                for (TreeNode *left : dp[leftLen])
                {
                    for (TreeNode *right : dp[rightLen])
                    {
                        TreeNode *newRoot = new TreeNode(root);
                        newRoot->left = cloneTree(left, 0);
                        newRoot->right = cloneTree(right, root);
                        dp[length].push_back(newRoot);
                    }
                }
            }
        }
        return dp[n];
    }

private:
    TreeNode *cloneTree(TreeNode *node, int offset)
    {
        if (!node)
        {
            return nullptr;
        }
        TreeNode *newNode = new TreeNode(node->val + offset);
        newNode->left = cloneTree(node->left, offset);
        newNode->right = cloneTree(node->right, offset);
        return newNode;
    }
};
// @lc code=end
