/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标 [KMP]
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size();
        if (n == 0)
        {
            return 0;
        }
        // 计算 next 数组
        vector<int> next(n, 0);
        for (int i = 1, j = 0; i < n; i++)
        {
            while (j > 0 && needle[i] != needle[j])
            {
                // 回溯
                j = next[j - 1];
            }
            if (needle[i] == needle[j])
            {
                j++;
            }
            next[i] = j;
        }

        // KMP
        for (int i = 0, j = 0; i < m; i++)
        {
            while (j > 0 && haystack[i] != needle[j])
            {
                // 回溯
                j = next[j - 1];
            }
            if (haystack[i] == needle[j])
            {
                j++;
            }
            if (j == n)
            {
                // 找到匹配项
                return i - n + 1;
            }
        }
        return -1;
    }
};
// @lc code=end
