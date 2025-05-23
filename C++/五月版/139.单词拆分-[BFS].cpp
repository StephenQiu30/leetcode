/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分 [BFS]
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        queue<int> queue;
        vector<bool> visited(s.size(), false);
        queue.push(0);
        while (!queue.empty())
        {
            int start = queue.front();
            queue.pop();
            if (visited[start])
            {
                continue;
            }
            for (int end = start + 1; end <= s.size(); end++)
            {
                if (dict.count(s.substr(start, end - start)))
                {
                    if (end == s.size())
                    {
                        return true;
                    }
                    queue.push(end);
                }
            }
            visited[start] = true;
        }
        return false;
    }
};
// @lc code=end
