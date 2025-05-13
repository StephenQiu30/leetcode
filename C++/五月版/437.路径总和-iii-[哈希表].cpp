/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III [哈希表]
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
    int pathSum(TreeNode *root, int targetSum)
    {
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1;
        return dfs(root, 0, targetSum, prefixSumCount);
    }

private:
    int dfs(TreeNode *node, long long currSum, int targetSum, unordered_map<long long, int> &prefixSumCount)
    {
        if (!node)
        {
            return 0;
        }

        currSum += node->val;
        int count = 0;
        if (prefixSumCount.count(currSum - targetSum))
        {
            count = prefixSumCount[currSum - targetSum];
        }
        prefixSumCount[currSum]++;
        count += dfs(node->left, currSum, targetSum, prefixSumCount);
        count += dfs(node->right, currSum, targetSum, prefixSumCount);
        prefixSumCount[currSum]--;
        return count;
    }
};
// @lc code=end
