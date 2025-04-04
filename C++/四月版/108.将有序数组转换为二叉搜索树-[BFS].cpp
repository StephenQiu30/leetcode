/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树 [BFS]
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
        if (nums.empty())
        {
            return nullptr;
        }
        queue<tuple<TreeNode **, int, int>> q;
        TreeNode *root = nullptr;
        q.emplace(&root, 0, nums.size() - 1);
        while (!q.empty())
        {
            auto [nodeRef, left, right] = q.front();
            q.pop();
            if (left > right)
            {
                continue;
            }
            int mid = left + (right - left) / 2;
            *nodeRef = new TreeNode(nums[mid]);
            q.emplace(&((*nodeRef)->left), left, mid - 1);
            q.emplace(&((*nodeRef)->right), mid + 1, right);
        }
        return root;
    }
};
// @lc code=end
