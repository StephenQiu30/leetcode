/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和 [模拟手算]
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result = "";
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
            {
                sum += a[i--] - '0';
            }
            if (j >= 0)
            {
                sum += b[j--] - '0';
            }
            // 头插法
            result = char(sum % 2 + '0') + result;
            carry = sum / 2;
        }
        return result;
    }
};
// @lc code=end
