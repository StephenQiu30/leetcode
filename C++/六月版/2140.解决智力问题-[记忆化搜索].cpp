/*
 * @lc app=leetcode.cn id=2140 lang=cpp
 *
 * [2140] 解决智力问题 [记忆化搜索]
 */

// @lc code=start
class Solution
{
public:
    vector<long long> memo;
    long long dfs(int i, vector<vector<int>> &questions)
    {
        if (i >= questions.size())
        {
            return 0;
        }
        if (memo[i] != -1)
        {
            return memo[i];
        }
        long long doIt = questions[i][0] + dfs(i + questions[i][1] + 1, questions);
        long long skipIt = dfs(i + 1, questions);
        return memo[i] = max(doIt, skipIt);
    }
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        memo.assign(n, -1);
        return dfs(0, questions);
    }
};
// @lc code=end
