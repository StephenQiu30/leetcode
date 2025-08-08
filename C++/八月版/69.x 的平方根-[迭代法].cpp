/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 [迭代法]
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        long long y = x;
        while (y * y > x)
        {
            y = (y + x / y) / 2;
        }
        return y;
    }
};
// @lc code=end
