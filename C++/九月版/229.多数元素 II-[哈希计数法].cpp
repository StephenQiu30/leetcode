/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 多数元素 II [哈希计数法]
 */

// @lc code=start
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res;
        unordered_map<int, int> count;
        for (int x : nums)
        {
            ++count[x];
        }
        int threshold = n / 3;
        for (auto &p : count)
        {
            if (p.second > threshold)
            {
                res.push_back(p.first);
            }
        }
        return res;
    }
};
// @lc code=end
