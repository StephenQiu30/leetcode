/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树) [索引数组]
 */

// @lc code=start
class Trie
{
    vector<array<int, 26>> next;
    vector<bool> isEnd;

public:
    Trie()
    {
        next.push_back(array<int, 26>());
        next[0].fill(-1);
        isEnd.push_back(false);
    }

    // 插入单词
    void insert(string word)
    {
        int node = 0;
        for (char ch : word)
        {
            int index = ch - 'a';
            if (next[node][index] == -1)
            {
                next[node][index] = next.size();
                next.push_back(array<int, 26>());
                next.back().fill(-1);
                isEnd.push_back(false);
            }
            node = next[node][index];
        }
        isEnd[node] = true;
    }

    // 搜索完全匹配单词
    bool search(string word)
    {
        int node = 0;
        for (char ch : word)
        {
            int index = ch - 'a';
            if (next[node][index] == -1)
            {
                return false;
            }
            node = next[node][index];
        }
        return isEnd[node];
    }

    // 判断是否存在以 prefix 为前缀的单词
    bool startsWith(string prefix)
    {
        int node = 0;
        for (char ch : prefix)
        {
            int index = ch - 'a';
            if (next[node][index] == -1)
            {
                return false;
            }
            node = next[node][index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
