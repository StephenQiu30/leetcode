/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径 [BFS]
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
public:
    // 建图（无向图），方便BFS
    void buildGraph(TreeNode *node, unordered_map<TreeNode *, vector<TreeNode *>> &graph)
    {
        if (!node)
        {
            return;
        }
        if (node->left)
        {
            graph[node].push_back(node->left);
            graph[node->left].push_back(node);
            buildGraph(node->left, graph);
        }
        if (node->right)
        {
            graph[node].push_back(node->right);
            graph[node->right].push_back(node);
            buildGraph(node->right, graph);
        }
    }

    // BFS 找最远的节点和路径长度
    pair<TreeNode *, int> bfs(TreeNode *start, unordered_map<TreeNode *, vector<TreeNode *>> &graph)
    {
        queue<TreeNode *> queue;
        unordered_set<TreeNode *> visited;
        queue.push(start);
        visited.insert(start);
        TreeNode *farthest = start;
        int level = -1;

        while (!queue.empty())
        {
            int size = queue.size();
            level++;
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = queue.front();
                queue.pop();
                farthest = node;
                for (TreeNode *neighbor : graph[node])
                {
                    if (!visited.count(neighbor))
                    {
                        visited.insert(neighbor);
                        queue.push(neighbor);
                    }
                }
            }
        }
        // level 即为最远路径的长度（边数）
        return {farthest, level};
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        unordered_map<TreeNode *, vector<TreeNode *>> graph;
        buildGraph(root, graph);
        // 第一次BFS找最远节点A
        auto [nodeA, _] = bfs(root, graph);
        // 第二次BFS从A出发找最远节点B
        auto [nodeB, diameter] = bfs(nodeA, graph);
        return diameter;
    }
};
// @lc code=end
