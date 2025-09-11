/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用 [Prim小根堆]
 */

// @lc code=start
class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n <= 1)
        {
            return 0;
        }
        // 当前每个点到MST的最近距离
        vector<int> minDist(n, INT_MAX);
        // 是否已加入MST
        vector<char> inMST(n, false);
        // min-heap: (dist, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // 从节点0开始
        pq.push({0, 0});
        long long ans = 0;
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            // 跳过已加入的过期条目
            if (inMST[u])
            {
                continue;
            }
            inMST[u] = true;
            ans += d;
            for (int v = 0; v < n; v++)
            {
                if (!inMST[v])
                {
                    int w = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    if (w < minDist[v])
                    {
                        minDist[v] = w;
                        pq.push({w, v});
                    }
                }
            }
        }
        return (int)ans;
    }
};
// @lc code=end
