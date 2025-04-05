/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一 [模拟加法]
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--)
        {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
            if (carry == 0)
            {
                break;
            }
        }
        if (carry)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
// @lc code=end
