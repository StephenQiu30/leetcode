/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径 [迭代]
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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        if (!root)
        {
            return res;
        }
        stack<pair<TreeNode *, string>> st;
        st.push({root, to_string(root->val)});
        while (!st.empty())
        {
            auto [node, path] = st.top();
            st.pop();
            if (!node->left && !node->right)
            {
                res.push_back(path);
                continue;
            }
            if (node->right)
            {
                st.push({node->right, path + "->" + to_string(node->right->val)});
            }
            if (node->left)
            {
                st.push({node->left, path + "->" + to_string(node->left->val)});
            }
        }
        return res;
    }
};
// @lc code=end
