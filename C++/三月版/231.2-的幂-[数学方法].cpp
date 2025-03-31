/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂 [数学方法]
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        double logRes = log10(n) / log10(2);
        // 判断是否是整数
        return floor(logRes) == logRes;
    }
};
// @lc code=end
