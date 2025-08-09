/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘 [模拟乘法]
 */

// @lc code=start
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        int n1 = num1.size(), n2 = num2.size();
        vector<int> pos(n1 + n2, 0);
        for (int i = n1 - 1; i >= 0; i--)
        {
            int d1 = num1[i] - '0';
            for (int j = n2 - 1; j >= 0; j--)
            {
                int d2 = num2[j] - '0';
                int mul = d1 * d2;
                int sum = mul + pos[i + j + 1];
                pos[i + j + 1] = sum % 10;
                pos[i + j] += sum / 10;
            }
        }
        string res;
        int i = 0;
        // 跳过前导 0
        while (i < (int)pos.size() && pos[i] == 0)
        {
            ++i;
        }
        for (; i < (int)pos.size(); ++i)
        {
            res.push_back(char('0' + pos[i]));
        }
        return res.empty() ? "0" : res;
    }
};
// @lc code=end
