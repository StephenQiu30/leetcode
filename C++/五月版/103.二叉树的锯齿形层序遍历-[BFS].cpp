/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历 [BFS]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
        {
            return result;
        }
        queue<TreeNode *> queue;
        queue.push(root);
        bool leftToRight = true;
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
            if (!leftToRight)
            {
                reverse(level.begin(), level.end());
            }
            result.push_back(level);
            // 每层切换方向
            leftToRight = !leftToRight;
        }
        return result;
    }
};
// @lc code=end
