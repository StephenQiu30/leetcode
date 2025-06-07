/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数 [BFS]
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        queue<int> queue;
        vector<bool> visited(n + 1, false);
        queue.push(n);
        visited[n] = true;
        int step = 0;
        while (!queue.empty())
        {
            int size = queue.size();
            step++;
            while (size--)
            {
                int current = queue.front();
                queue.pop();
                for (int i = 1; i * i <= current; i++)
                {
                    int next = current - i * i;
                    if (next == 0)
                    {
                        return step;
                    }
                    if (!visited[next])
                    {
                        queue.push(next);
                        visited[next] = true;
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end
