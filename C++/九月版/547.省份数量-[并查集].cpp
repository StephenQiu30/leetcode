/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量 [并查集]
 */

// @lc code=start
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);
        int sets = n;

        // 路径压缩查找根节点
        function<int(int)> find = [&](int x)
        {
            if (parent[x] != x)
            {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        // 按秩合并
        auto unite = [&](int a, int b)
        {
            int ra = find(a), rb = find(b);
            if (ra == rb)
            {
                return;
            }
            if (rank[ra] < rank[rb])
            {
                swap(ra, rb);
            }
            parent[rb] = ra;
            if (rank[ra] == rank[rb])
            {
                ++rank[ra];
            }
            --sets;
        };

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    unite(i, j);
                }
            }
        }
        return sets;
    }
};
// @lc code=end
