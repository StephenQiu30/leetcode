/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II [DFS]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        unordered_map<int, int> counter;
        for (int num : candidates)
        {
            counter[num]++;
        }

        // 转为排序好的频次数组
        vector<pair<int, int>> frequent;
        for (auto &kv : counter)
        {
            frequent.emplace_back(kv.first, kv.second);
        }
        sort(frequent.begin(), frequent.end());

        dfs(frequent, target, 0);
        return result;
    }

private:
    void dfs(vector<pair<int, int>> &frequent, int target, int index)
    {
        if (target == 0)
        {
            result.push_back(path);
            return;
        }
        if (index == frequent.size() || target < frequent[index].first)
        {
            return;
        }
        // 不选当前数
        dfs(frequent, target, index + 1);
        // 最多可以选择 cnt 次当前数
        int value = frequent[index].first;
        int count = frequent[index].second;
        for (int i = 1; i <= count; i++)
        {
            if (target < i * value)
            {
                break;
            }
            path.push_back(value);
            dfs(frequent, target - i * value, index + 1);
        }
        // 回溯
        for (int i = 1; i <= count && i * value <= target; ++i)
        {
            path.pop_back();
        }
    }
};
// @lc code=end
