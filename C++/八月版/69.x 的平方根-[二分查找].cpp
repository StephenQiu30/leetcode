/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 [二分查找]
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1)
        {
            return x;
        }
        int left = 0, right = x / 2 + 1;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            if (mid * mid == x)
            {
                return mid;
            }
            else if (mid * mid < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        // 此时 right 是满足条件的最大整数
        return right;
    }
};
// @lc code=end
