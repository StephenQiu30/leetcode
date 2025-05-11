/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树 [递归]
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
    unordered_map<int, int> inorderIndex;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            inorderIndex[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode *build(vector<int> &preorder, int preLeft, int preRight, vector<int> &inorder, int inLeft, int inRight)
    {
        if (preLeft > preRight || inLeft > inRight)
        {
            return nullptr;
        }
        int rootVal = preorder[preLeft];
        TreeNode *root = new TreeNode(rootVal);
        // 在中序中找根节点位置
        int rootIndexInInorder = inorderIndex[rootVal];
        int leftTreeSize = rootIndexInInorder - inLeft;
        // 构建左子树
        root->left = build(preorder, preLeft + 1, preLeft + leftTreeSize,
                           inorder, inLeft, rootIndexInInorder - 1);
        // 构建右子树
        root->right = build(preorder, preLeft + leftTreeSize + 1, preRight,
                            inorder, rootIndexInInorder + 1, inRight);
        return root;
    }
};
// @lc code=end
