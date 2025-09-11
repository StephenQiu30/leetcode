/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用 [Prim数组算法]
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
        // 从点0开始
        minDist[0] = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int u = -1;
            int best = INT_MAX;
            // 找到未加入MST且 minDist 最小的点 u
            for (int j = 0; j < n; j++)
            {
                if (!inMST[j] && minDist[j] < best)
                {
                    best = minDist[j];
                    u = j;
                }
            }
            // u 必然存在（完全图连通）
            inMST[u] = true;
            // 第一次加入时 best = 0（对起点）
            ans += best;
            // 用新加入的 u 去更新其它点的 minDist
            for (int v = 0; v < n; ++v)
            {
                if (!inMST[v])
                {
                    int w = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    if (w < minDist[v])
                    {
                        minDist[v] = w;
                    }
                }
            }
        }
        return (int)ans;
    }
};
// @lc code=end
