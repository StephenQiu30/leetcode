/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组 [排序法]
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
            string key = str;
            sort(key.begin(), key.end());
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
