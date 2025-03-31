/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历 [DFS（深度优先搜索）]
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        dfs(root, result, 0);
        return result;
    }

private:
    void dfs(TreeNode *node, vector<vector<int>> &result, int depth)
    {
        if (node == nullptr)
        {
            return;
        }
        if (depth == result.size())
        {
            result.push_back({});
        }
        result[depth].push_back(node->val);
        dfs(node->left, result, depth + 1);
        dfs(node->right, result, depth + 1);
    }
};
// @lc code=end
