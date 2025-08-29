/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表 [BFS]
 */

// @lc code=start
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> g(numCourses);
        vector<int> indeg(numCourses, 0);
        for (const auto &e : prerequisites)
        {
            int a = e[0], b = e[1];
            g[b].push_back(a);
            ++indeg[a];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        int current = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            ++current;
            for (int v : g[u])
            {
                if (--indeg[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        return current == numCourses;
    }
};
// @lc code=end
