/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器 [中序遍历]
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
class BSTIterator
{
private:
    vector<int> vals;
    int index;
    void inorder(TreeNode *node)
    {
        if (!node)
        {
            return;
        }
        inorder(node->left);
        vals.push_back(node->val);
        inorder(node->right);
    }

public:
    BSTIterator(TreeNode *root) : index(0)
    {
        inorder(root);
    }

    int next()
    {
        return vals[index++];
    }

    bool hasNext()
    {
        return index < (int)vals.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
