/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和 [记忆化搜索]
 */

// @lc code=start
class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dfs(s1, s2, 0, 0, memo);
    }
    int dfs(const string &s1, const string &s2, int i, int j, vector<vector<int>> &memo)
    {
        if (i == s1.size())
        {
            int sum = 0;
            for (int k = j; k < s2.size(); k++)
            {
                sum += s2[k];
            }
            return sum;
        }
        if (j == s2.size())
        {
            int sum = 0;
            for (int k = i; k < s1.size(); k++)
            {
                sum += s1[k];
            }
            return sum;
        }
        if (memo[i][j] != -1)
        {
            return memo[i][j];
        }
        if (s1[i] == s2[j])
        {
            return memo[i][j] = dfs(s1, s2, i + 1, j + 1, memo);
        }
        else
        {
            int deleteS1 = s1[i] + dfs(s1, s2, i + 1, j, memo);
            int deleteS2 = s2[j] + dfs(s1, s2, i, j + 1, memo);
            return memo[i][j] = min(deleteS1, deleteS2);
        }
    }
};
// @lc code=end
