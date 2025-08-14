/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址 [回溯 + 剪枝]
 */

// @lc code=start
class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        int n = s.size();
        if (n < 4 || n > 12)
        {
            return ans; // 粗剪枝
        }

        vector<string> path;
        dfs(s, 0, 0, path, ans);
        return ans;
    }

private:
    void dfs(const string &s, int i, int seg, vector<string> &path, vector<string> &ans)
    {
        int n = s.size();
        int rem = n - i;
        // 长度剪枝
        if (rem < (4 - seg) || rem > (4 - seg) * 3)
        {
            return;
        }

        if (seg == 4)
        { // 放满4段
            if (i == n)
            { // 恰好用完
                ans.push_back(join(path));
            }
            return;
        }

        // 取1~3位作为一段
        int val = 0;
        for (int len = 1; len <= 3 && i + len <= n; ++len)
        {
            // 前导零规则：如果首位是'0'，只能取长度1
            if (len > 1 && s[i] == '0')
                break;

            val = val * 10 + (s[i + len - 1] - '0');
            if (val > 255)
                break;

            path.push_back(s.substr(i, len));
            dfs(s, i + len, seg + 1, path, ans);
            path.pop_back();
        }
    }
    string join(const vector<string> &parts)
    {
        string res;
        for (int k = 0; k < 4; ++k)
        {
            if (k)
            {
                res.push_back('.');
            }
            res += parts[k];
        }
        return res;
    }
};
// @lc code=end
