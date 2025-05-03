/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串 [栈]
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
    string tree2str(TreeNode *root)
    {
        if (!root)
        {
            return "";
        }
        stack<TreeNode *> stack;
        unordered_set<TreeNode *> visited;
        string res;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode *node = stack.top();

            if (visited.count(node))
            {
                stack.pop();
                res += ")";
            }
            else
            {
                visited.insert(node);
                res += "(" + to_string(node->val);

                if (!node->left && node->right)
                {
                    res += "()";
                }

                if (node->right)
                {
                    stack.push(node->right);
                }
                if (node->left)
                {
                    stack.push(node->left);
                }
            }
        }
        // 去除最外层的括号
        return res.substr(1, res.size() - 2);
    }
};
// @lc code=end
