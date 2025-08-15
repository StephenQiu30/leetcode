/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂 [递归判断]
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n == 1)
        {
            return true;
        }
        if (n <= 0 || n % 4 != 0)
        {
            return false;
        }
        return isPowerOfFour(n / 4);
    }
};
// @lc code=end
