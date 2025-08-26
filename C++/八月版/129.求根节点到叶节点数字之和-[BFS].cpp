/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和 [BFS]
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
    int sumNumbers(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        queue<TreeNode *> nodeQueue;
        queue<int> sumQueue;
        nodeQueue.push(root);
        sumQueue.push(root->val);
        int result = 0;
        while (!nodeQueue.empty())
        {
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();
            int currentSum = sumQueue.front();
            sumQueue.pop();
            if (!node->left && !node->right)
            {
                result += currentSum;
            }
            if (node->left)
            {
                nodeQueue.push(node->left);
                sumQueue.push(currentSum * 10 + node->left->val);
            }
            if (node->right)
            {
                nodeQueue.push(node->right);
                sumQueue.push(currentSum * 10 + node->right->val);
            }
        }
        return result;
    }
};
// @lc code=end
