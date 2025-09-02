/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II [BFS]
 */

// @lc code=start
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> g(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto &p : prerequisites)
        {
            g[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> order;
        order.reserve(numCourses);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (int v : g[u])
            {
                if (--indeg[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        if (order.size() != numCourses)
        {
            return {};
        }
        return order;
    }
};
// @lc code=end
