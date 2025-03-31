/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历 [迭代法]
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> stack;
        TreeNode *current = root;
        while (current != nullptr || !stack.empty())
        {
            // 先把左子树的所有节点压入栈
            while (current != nullptr)
            {
                stack.push(current);
                current = current->left;
            }
            // 取出栈顶元素
            current = stack.top();
            stack.pop();
            // 访问当前节点
            result.push_back(current->val);
            // 转向右子树
            current = current->right;
        }

        return result;
    }
};
// @lc code=end
