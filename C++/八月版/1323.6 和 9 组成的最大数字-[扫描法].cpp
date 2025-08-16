/*
 * @lc app=leetcode.cn id=1323 lang=cpp
 *
 * [1323] 6 和 9 组成的最大数字 [扫描法]
 */

// @lc code=start
class Solution
{
public:
    int maximum69Number(int num)
    {
        int x = num;
        int power = 1;
        int bestAdd = 0;
        while (x > 0)
        {
            int digit = (x % 10);
            if (digit == 6)
            {
                bestAdd = 3 * power;
            }
            x /= 10;
            power *= 10;
        }
        return num + bestAdd;
    }
};
// @lc code=end
