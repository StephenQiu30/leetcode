/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图 [DFS]
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
    vector<int> res;
    vector<int> rightSideView(TreeNode *root)
    {
        dfs(root, 0);
        return res;
    }

private:
    void dfs(TreeNode *node, int depth)
    {
        if (!node)
        {
            return;
        }
        if (depth == res.size())
        {
            // 只记录每层的第一个节点（右边优先）
            res.push_back(node->val);
        }
        // 必须先访问右子树
        dfs(node->right, depth + 1);
        dfs(node->left, depth + 1);
    }
};
// @lc code=end
