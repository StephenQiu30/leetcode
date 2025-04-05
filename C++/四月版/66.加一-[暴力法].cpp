/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        // 如果全部都是9，比如999，处理完变成000，此时需要在前面加1 => 1000
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
// @lc code=end
