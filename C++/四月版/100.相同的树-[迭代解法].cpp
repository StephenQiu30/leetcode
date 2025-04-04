/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树 [迭代解法]
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        queue<TreeNode *> queue;
        queue.push(p);
        queue.push(q);
        while (!queue.empty())
        {
            TreeNode *node1 = queue.front();
            queue.pop();
            TreeNode *node2 = queue.front();
            queue.pop();
            if (!node1 && !node2)
            {
                continue;
            }
            if (!node1 || !node2 || node1->val != node2->val)
            {
                return false;
            }
            queue.push(node1->left);
            queue.push(node2->left);
            queue.push(node1->right);
            queue.push(node2->right);
        }
        return true;
    }
};
// @lc code=end
