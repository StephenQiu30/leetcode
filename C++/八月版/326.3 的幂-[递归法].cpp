/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂 [递归法]
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n == 1)
        {
            return true;
        }
        if (n <= 0 || n % 3 != 0)
        {
            return false;
        }
        return isPowerOfThree(n / 3);
    }
};
// @lc code=end
