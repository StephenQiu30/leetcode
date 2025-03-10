/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II [DFS（深度优先搜索）]
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
        dfs(root, result, 0);
        // 反转列表，得到自底向上的顺序
        reverse(result.begin(), result.end());
        return result;
    }

private:
    void dfs(TreeNode *node, vector<vector<int>> &result, int depth)
    {
        if (node == nullptr)
        {
            return;
        }
        if (depth >= result.size())
        {
            // 如果当前层不存在，则创建新的一层
            result.push_back({});
        }
        // 将当前节点值加入对应层级
        result[depth].push_back(node->val);
        // 递归左子树
        dfs(node->left, result, depth + 1);
        // 递归右子树
        dfs(node->right, result, depth + 1);
    }
};
// @lc code=end
