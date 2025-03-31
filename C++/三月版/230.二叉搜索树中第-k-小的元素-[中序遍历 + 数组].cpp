/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素 [中序遍历 + 数组]
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
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> nums;
        inOrder(root, nums);
        return nums[k - 1];
    }

private:
    void inOrder(TreeNode *node, vector<int> &nums)
    {
        // 递归调用终止条件
        if (!node)
        {
            return;
        }
        inOrder(node->left, nums);
        nums.push_back(node->val);
        inOrder(node->right, nums);
    }
};
// @lc code=end
