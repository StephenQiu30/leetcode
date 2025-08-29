/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表 [DFS]
 */

// @lc code=start
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        g.assign(numCourses, {});
        color.assign(numCourses, 0);
        for (const auto &e : prerequisites)
        {
            // b -> a
            int a = e[0], b = e[1];
            g[b].push_back(a);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (color[i] == 0)
            {
                if (!dfs(i))
                {
                    return false;
                }
            }
        }
        return true;
    }

private:
    vector<vector<int>> g;
    // 0=未访问,1=递归中,2=已完成
    vector<int> color;
    bool dfs(int u)
    {
        color[u] = 1;
        for (int v : g[u])
        {
            if (color[v] == 0)
            {
                if (!dfs(v))
                {
                    return false;
                }
            }
            else if (color[v] == 1)
            {
                // 回边 -> 有环
                return false;
            }
        }
        color[u] = 2;
        return true;
    }
};
// @lc code=end
