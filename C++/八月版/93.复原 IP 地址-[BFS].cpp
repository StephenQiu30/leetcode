/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址 [BFS]
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
            return ans;
        }

        struct Node
        {
            int idx;
            vector<string> parts;
        };
        queue<Node> q;
        q.push({0, {}});

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            int seg = (int)cur.parts.size();

            // 长度剪枝
            int rem = n - cur.idx;
            if (rem < (4 - seg) || rem > (4 - seg) * 3)
                continue;

            if (seg == 4)
            {
                if (cur.idx == n)
                {
                    ans.push_back(join(cur.parts));
                }
                continue;
            }

            int val = 0;
            for (int len = 1; len <= 3 && cur.idx + len <= n; ++len)
            {
                if (len > 1 && s[cur.idx] == '0')
                    break;
                val = val * 10 + (s[cur.idx + len - 1] - '0');
                if (val > 255)
                    break;

                auto nxt = cur;
                nxt.idx = cur.idx + len;
                nxt.parts.push_back(s.substr(cur.idx, len));
                q.push(std::move(nxt));
            }
        }
        return ans;
    }

private:
    static string join(const vector<string> &parts)
    {
        return parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3];
    }
};
// @lc code=end
