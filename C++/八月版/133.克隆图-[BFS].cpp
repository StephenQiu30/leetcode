/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图 [BFS]
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
        queue<Node *> q;
        q.push(node);
        mp[node] = new Node(node->val);
        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();
            for (Node *neighbor : current->neighbors)
            {
                if (!mp.count(neighbor))
                {
                    mp[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                mp[current]->neighbors.push_back(mp[neighbor]);
            }
        }
        return mp[node];
    }
};
// @lc code=end
