/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘 [字符串相加]
 */

// @lc code=start
class Solution
{
public:
    // 把 num1 * singleDigit(0-9) 生成字符串（不带尾部补0）
    string multiplyOneDigit(const string &num1, int digit)
    {
        if (digit == 0)
        {
            return "0";
        }
        int carry = 0;
        string cur;
        for (int i = (int)num1.size() - 1; i >= 0; --i)
        {
            int prod = (num1[i] - '0') * digit + carry;
            cur.push_back(char('0' + (prod % 10)));
            carry = prod / 10;
        }
        while (carry)
        {
            cur.push_back(char('0' + (carry % 10)));
            carry /= 10;
        }
        reverse(cur.begin(), cur.end());
        return cur;
    }

    // 字符串大小整数相加
    string addStrings(const string &a, const string &b)
    {
        int i = (int)a.size() - 1, j = (int)b.size() - 1, carry = 0;
        string s;
        while (i >= 0 || j >= 0 || carry)
        {
            int x = (i >= 0 ? a[i] - '0' : 0);
            int y = (j >= 0 ? b[j] - '0' : 0);
            int sum = x + y + carry;
            s.push_back(char('0' + sum % 10));
            carry = sum / 10;
            --i;
            --j;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        string res = "0";
        int zeros = 0; // 记录补多少个 0（相当于位移）
        for (int j = (int)num2.size() - 1; j >= 0; --j)
        {
            int d = num2[j] - '0';
            string part = multiplyOneDigit(num1, d);
            if (part != "0")
            {
                part.append(zeros, '0'); // 在末尾补 zeros 个 '0'
                res = addStrings(res, part);
            }
            ++zeros;
        }
        // 去掉可能的前导0（通常不会有）
        int p = 0;
        while (p + 1 < (int)res.size() && res[p] == '0')
        {
            ++p;
        }
        return res.substr(p);
    }
};
// @lc code=end
