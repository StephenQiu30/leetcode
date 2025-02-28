/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组 [计数法]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // 先创建一个哈希表
        unordered_map<string, vector<string>> hashmap;
        for (string str : strs)
        {
            // 定义一个列表用户记录每一个字符来存储每个字母出现的次数
            vector<int> count(26, 0);
            for (char c : str)
            {
                count[c - 'a']++;
            }
            // 将技术数组转换为字符串作为key
            string key;
            for (int num : count)
            {
                key += to_string(num) + '#';
            }
            // 将原字符加入对应的 key 下
            hashmap[key].push_back(str);
        }
        // 将哈希表中的所有的 value 收集起来
        vector<vector<string>> result;
        for (auto &pair : hashmap)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};
// @lc code=end
