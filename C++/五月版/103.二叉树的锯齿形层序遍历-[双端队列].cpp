/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历 [双端队列]
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
            // 允许头部插入
            deque<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = queue.front();
                queue.pop();
                if (leftToRight)
                {
                    level.push_back(node->val);
                }
                else
                {
                    level.push_front(node->val);
                }
                if (node->left)
                {
                    queue.push(node->left);
                }

                if (node->right)
                {
                    queue.push(node->right);
                }
            }
            result.push_back(vector<int>(level.begin(), level.end()));
            leftToRight = !leftToRight;
        }
        return result;
    }
};
// @lc code=end
