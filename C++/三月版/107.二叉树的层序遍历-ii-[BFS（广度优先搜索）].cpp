/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II [BFS（广度优先搜索）]
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
        {
            return result;
        }
        queue<TreeNode *> queue;
        queue.push(root);

        while (!queue.empty())
        {
            int size = queue.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = queue.front();
                queue.pop();
                level.push_back(node->val);
                if (node->left)
                {
                    queue.push(node->left);
                }
                if (node->right)
                {
                    queue.push(node->right);
                }
            }
            result.push_back(level);
        }
        // 反转得到自底向上的顺序
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
