/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接 [并查集]
 */

// @lc code=start
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> parent(n + 1), rankv(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> findp = [&](int x) -> int
        {
            return parent[x] == x ? x : parent[x] = findp(parent[x]);
        };
        for (auto &e : edges)
        {
            int u = e[0], v = e[1];
            int pu = findp(u), pv = findp(v);
            if (pu == pv)
            {
                // 找到冗余边
                return {u, v};
            }
            // 按秩合并
            if (rankv[pu] < rankv[pv])
            {
                parent[pu] = pv;
            }
            else if (rankv[pu] > rankv[pv])
            {
                parent[pv] = pu;
            }
            else
            {
                parent[pv] = pu;
                rankv[pu]++;
            }
        }
        return {};
    }
};
// @lc code=end
