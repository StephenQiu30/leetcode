/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图 [DFS]
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
        {
            return nullptr;
        }
        unordered_map<Node *, Node *> mp;
        return dfs(node, mp);
    }

private:
    Node *dfs(Node *current, unordered_map<Node *, Node *> &mp)
    {
        if (mp.count(current))
        {
            return mp[current];
        }
        Node *copy = new Node(current->val);
        mp[current] = copy;
        for (Node *neighbor : current->neighbors)
        {
            copy->neighbors.push_back(dfs(neighbor, mp));
        }
        return copy;
    }
};
// @lc code=end
