/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级 [动态规划]
 */

// @lc code=start
class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> nums;
        vector<char> ops;

        // 解析数字和运算符
        long long cur = 0;
        bool inNumber = false;
        for (int i = 0; i < (int)expression.size(); ++i)
        {
            char c = expression[i];
            if (isdigit(c))
            {
                cur = cur * 10 + (c - '0');
                inNumber = true;
            }
            else
            { // 运算符
                if (inNumber)
                {
                    nums.push_back((int)cur);
                    cur = 0;
                    inNumber = false;
                }
                ops.push_back(c);
            }
        }
        if (inNumber)
        {
            nums.push_back((int)cur);
        }

        int m = nums.size();
        // dp[i][j] : vector<int> results for nums[i..j]
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(m));
        for (int i = 0; i < m; ++i)
        {
            dp[i][i].push_back(nums[i]);
        }

        for (int len = 2; len <= m; ++len)
        { // 区间长度（数字个数）
            for (int i = 0; i + len - 1 < m; ++i)
            {
                int j = i + len - 1;
                vector<int> results;
                for (int k = i; k < j; ++k)
                { // 在 ops[k] 处划分
                    char op = ops[k];
                    const vector<int> &L = dp[i][k];
                    const vector<int> &R = dp[k + 1][j];
                    for (int a : L)
                    {
                        for (int b : R)
                        {
                            if (op == '+')
                            {
                                results.push_back(a + b);
                            }
                            else if (op == '-')
                            {
                                results.push_back(a - b);
                            }
                            else if (op == '*')
                            {
                                results.push_back(a * b);
                            }
                        }
                    }
                }
                dp[i][j] = std::move(results);
            }
        }
        return m ? dp[0][m - 1] : vector<int>{};
    }
};
// @lc code=end
