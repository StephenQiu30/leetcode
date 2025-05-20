/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II [栈]
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
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> result;
        if (!root)
        {
            return result;
        }
        stack<tuple<TreeNode *, int, vector<int>>> stack;
        stack.push({root, root->val, {root->val}});
        while (!stack.empty())
        {
            auto [node, sum, path] = stack.top();
            stack.pop();
            if (!node->left && !node->right && sum == targetSum)
            {
                result.push_back(path);
            }
            if (node->right)
            {
                auto new_path = path;
                new_path.push_back(node->right->val);
                stack.push({node->right, sum + node->right->val, new_path});
            }
            if (node->left)
            {
                auto new_path = path;
                new_path.push_back(node->left->val);
                stack.push({node->left, sum + node->left->val, new_path});
            }
        }
        return result;
    }
};
// @lc code=end
