/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转 [更简单的数学实现]
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        long long revLL = 0;
        int t = x;
        while (t != 0)
        {
            int pop = t % 10;
            t /= 10;
            revLL = revLL * 10 + pop;
        }
        if (revLL < INT_MIN || revLL > INT_MAX)
        {
            return 0;
        }
        return (int)revLL;
    }
};
// @lc code=end
