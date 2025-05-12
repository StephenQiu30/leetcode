/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先 [哈希表]
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    unordered_map<TreeNode *, TreeNode *> parent;
    unordered_set<TreeNode *> visited;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        parent[root] = nullptr;
        dfs(root);
        while (p)
        {
            visited.insert(p);
            p = parent[p];
        }
        while (q)
        {
            if (visited.count(q))
            {
                return q;
            }
            q = parent[q];
        }
        return nullptr;
    }

private:
    void dfs(TreeNode *node)
    {
        if (node->left)
        {
            parent[node->left] = node;
            dfs(node->left);
        }
        if (node->right)
        {
            parent[node->right] = node;
            dfs(node->right);
        }
    }
};
// @lc code=end
