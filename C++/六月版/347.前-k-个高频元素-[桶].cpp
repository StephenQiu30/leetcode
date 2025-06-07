/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素 [桶]
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> frequent;
        for (int num : nums)
        {
            frequent[num]++;
        }
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for (auto &[num, count] : frequent)
        {
            buckets[count].push_back(num);
        }

        vector<int> res;
        for (int i = n; i >= 0 && res.size() < k; --i)
        {
            for (int num : buckets[i])
            {
                res.push_back(num);
                if (res.size() == k)
                    break;
            }
        }

        return res;
    }
};
// @lc code=end
