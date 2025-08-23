/*
 * @lc app=leetcode.cn id=3304 lang=cpp
 *
 * [3304] 找出第 K 个字符 I [暴力法]
 */

// @lc code=start
class Solution
{
public:
    char kthCharacter(int k)
    {
        string s = "1";
        int num = 2;
        while (s.size() < k)
        {
            // 根据规律扩展下一个字符 num
            s += to_string(num);
            // 假设规律是 1,2,3,1,2,3...
            num = (num == 3 ? 1 : num + 1);
        }
        // 返回第 k 个字符
        return s[k - 1];
    }
};
// @lc code=end
