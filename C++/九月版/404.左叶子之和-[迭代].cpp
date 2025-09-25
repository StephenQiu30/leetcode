/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和 [迭代]
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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int sum = 0;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            if (!node)
            {
                continue;
            }
            if (node->left)
            {
                if (!node->left->left && !node->left->right)
                {
                    sum += node->left->val;
                }
                else
                {
                    st.push(node->left);
                }
            }
            if (node->right)
            {
                st.push(node->right);
            }
        }
        return sum;
    }
};
// @lc code=end
