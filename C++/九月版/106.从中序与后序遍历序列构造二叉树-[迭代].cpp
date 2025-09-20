/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树 [迭代]
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = postorder.size();
        if (n == 0)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(postorder[n - 1]);
        stack<TreeNode *> st;
        st.push(root);
        int inIndex = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            TreeNode *node = new TreeNode(postorder[i]);
            TreeNode *top = st.top();
            if (top->val != inorder[inIndex])
            {
                // 新节点是当前栈顶的右子节点
                top->right = node;
                st.push(node);
            }
            else
            {
                // 回溯：pop 出和 inorder[inIndex] 匹配的所有节点
                while (!st.empty() && st.top()->val == inorder[inIndex])
                {
                    top = st.top();
                    st.pop();
                    inIndex--;
                }
                // 把新节点作为最后一个被 pop 出来的节点的左子节点
                top->left = node;
                st.push(node);
            }
        }
        return root;
    }
};
// @lc code=end
