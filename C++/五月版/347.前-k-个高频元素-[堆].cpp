/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素 [堆]
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
        // 小顶堆：pair的first是频率，second是数字
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        for (auto &[num, count] : frequent)
        {
            minHeap.emplace(count, num);
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
        vector<int> res;
        while (!minHeap.empty())
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};
// @lc code=end
