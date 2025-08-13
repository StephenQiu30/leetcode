/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        while (n % 3 == 0)
        {
            n /= 3;
        }
        return n == 1;
    }
};
// @lc code=end
