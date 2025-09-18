/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树) [指针数组]
 */

// @lc code=start
class Trie
{
    struct Node
    {
        Node *next[26];
        bool isEnd;
        Node()
        {
            memset(next, 0, sizeof next);
            isEnd = false;
        }
    };
    Node *root;
    void clear(Node *p)
    {
        if (!p)
        {
            return;
        }
        for (int i = 0; i < 26; i++)
        {
            clear(p->next[i]);
        }
        delete p;
    }

public:
    Trie()
    {
        root = new Node();
    }
    ~Trie()
    {
        clear(root);
    }

    // 插入单词
    void insert(string word)
    {
        Node *p = root;
        for (char ch : word)
        {
            int index = ch - 'a';
            if (!p->next[index])
            {
                p->next[index] = new Node();
            }
            p = p->next[index];
        }
        p->isEnd = true;
    }

    // 搜索完全匹配单词
    bool search(string word)
    {
        Node *p = root;
        for (char ch : word)
        {
            int index = ch - 'a';
            if (!p->next[index])
            {
                return false;
            }
            p = p->next[index];
        }
        return p->isEnd;
    }

    // 判断是否存在以 prefix 为前缀的单词
    bool startsWith(string prefix)
    {
        Node *p = root;
        for (char ch : prefix)
        {
            int idx = ch - 'a';
            if (!p->next[idx])
                return false;
            p = p->next[idx];
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
