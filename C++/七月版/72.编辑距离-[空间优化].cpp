/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离 [空间优化]
 */

// @lc code=start
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<int> prev(n + 1), current(n + 1);
        for (int j = 0; j <= n; j++)
        {
            prev[j] = j;
        }
        for (int i = 1; i <= m; i++)
        {
            current[0] = i;
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    current[j] = prev[j - 1];
                }
                else
                {
                    current[j] = min({
                        prev[j] + 1,        // 删除
                        current[j - 1] + 1, // 插入
                        prev[j - 1] + 1     // 替换
                    });
                }
            }
            swap(prev, current);
        }
        return prev[n];
    }
};
// @lc code=end
