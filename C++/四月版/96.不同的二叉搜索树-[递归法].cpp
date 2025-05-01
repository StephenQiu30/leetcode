/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树 [递归法]
 */

// @lc code=start
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> memo(n + 1, -1);
        return countTrees(n, memo);
    }

private:
    int countTrees(int n, vector<int> &memo)
    {
        if (n <= 1)
        {
            return 1;
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            res += countTrees(i - 1, memo) * countTrees(n - i, memo);
        }
        memo[n] = res;
        return res;
    }
};
// @lc code=end
