/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树 [迭代 + 分治]
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return buildTree(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *buildTree(vector<int> &nums, int left, int right)
    {
        // 递归终止条件
        if (left > right)
        {
            return nullptr;
        }
        // 取中间元素
        int mid = left + (right - left) / 2;
        // 创建根节点
        TreeNode *root = new TreeNode(nums[mid]);
        // 构建左子树
        root->left = buildTree(nums, left, mid - 1);
        // 构建右子树
        root->right = buildTree(nums, mid + 1, right);
        return root;
    }
};
// @lc code=end
