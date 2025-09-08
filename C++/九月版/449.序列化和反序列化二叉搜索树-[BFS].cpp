/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树 [BFS]
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s;
        function<void(TreeNode *)> pre = [&](TreeNode *node)
        {
            if (!node)
            {
                return;
            }
            if (!s.empty())
            {
                s.push_back(',');
            }
            s += to_string(node->val);
            pre(node->left);
            pre(node->right);
        };
        pre(root);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
        {
            return nullptr;
        }
        // 把逗号替换为空格，然后用 istringstream 读数（支持负数）
        for (char &c : data)
        {
            if (c == ',')
            {
                c = ' ';
            }
        }
        istringstream iss(data);
        int x;
        TreeNode *root = nullptr;
        while (iss >> x)
        {
            root = insertNode(root, x);
        }
        return root;
    }

    TreeNode *insertNode(TreeNode *root, int v)
    {
        if (!root)
        {
            return new TreeNode(v);
        }
        if (v < root->val)
        {
            root->left = insertNode(root->left, v);
        }
        else
        {
            root->right = insertNode(root->right, v); // 若允许重复值，重复走右子树
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
