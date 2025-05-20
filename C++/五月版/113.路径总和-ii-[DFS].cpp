/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II [DFS]
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
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        dfs(root, targetSum);
        return result;
    }
    void dfs(TreeNode *node, int target)
    {
        if (!node)
        {
            return;
        }
        path.push_back(node->val);
        target -= node->val;
        // 是叶子节点且路径和为目标值
        if (!node->left && !node->right && target == 0)
        {
            // 注意要复制 path
            result.push_back(path);
        }
        dfs(node->left, target);
        dfs(node->right, target);
        // 回溯
        path.pop_back();
    }
};
// @lc code=end
