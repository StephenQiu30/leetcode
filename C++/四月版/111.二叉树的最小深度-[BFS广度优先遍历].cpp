/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度 [BFS广度优先遍历]
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
    int minDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        queue<pair<TreeNode *, int>> queue;
        queue.push({root, 1});
        while (!queue.empty())
        {
            auto [node, depth] = queue.front();
            queue.pop();
            if (!node->left && !node->right)
            {
                return depth;
            }
            if (node->left)
            {
                queue.push({node->left, depth + 1});
            }
            if (node->right)
            {
                queue.push({node->right, depth + 1});
            }
        }
        return 0;
    }
};
// @lc code=end
