/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值 [并查集]
 */

// @lc code=start
class Solution
{
public:
    unordered_map<string, string> parent;
    unordered_map<string, double> weight;
    string find(const string &x)
    {
        // 递归实现带路径压缩，注意更新 weight
        if (parent[x] == x)
        {
            return x;
        }
        string p = parent[x];
        string r = find(p);
        // x/oldParent * oldParent/root => x/root
        weight[x] *= weight[p];
        parent[x] = r;
        return parent[x];
    }
    void unite(const string &x, const string &y, double value)
    {
        if (!parent.count(x))
        {
            parent[x] = x;
            weight[x] = 1.0;
        }
        if (!parent.count(y))
        {
            parent[y] = y;
            weight[y] = 1.0;
        }
        string rx = find(x);
        string ry = find(y);
        if (rx == ry)
        {
            return;
        }
        // 要满足： val = x / y
        // 已知： weight[x] = x / rx ， weight[y] = y / ry
        // 我们令 parent[rx] = ry，则需设置 weight[rx] = rx / ry
        // 由 val = (x/rx) * (rx/ry) * (ry/y) = weight[x] * weight_rx * (1/weight[y])
        // => weight_rx = val * weight[y] / weight[x]
        parent[rx] = ry;
        weight[rx] = value * weight[y] / weight[x];
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        parent.clear();
        weight.clear();
        int m = equations.size();
        for (int i = 0; i < m; ++i)
        {
            string a = equations[i][0], b = equations[i][1];
            double v = values[i];
            unite(a, b, v);
        }

        vector<double> ans;
        for (auto &q : queries)
        {
            string x = q[0], y = q[1];
            if (!parent.count(x) || !parent.count(y))
            {
                ans.push_back(-1.0);
                continue;
            }
            string rx = find(x), ry = find(y);
            if (rx != ry)
            {
                ans.push_back(-1.0);
                continue;
            }
            // a/b = (a/root) / (b/root)
            ans.push_back(weight[x] / weight[y]);
        }
        return ans;
    }
};
// @lc code=end
