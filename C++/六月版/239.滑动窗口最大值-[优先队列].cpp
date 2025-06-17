/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值 [优先队列]
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.emplace(nums[i], i);
            if (i >= k - 1)
            {
                while (pq.top().second <= i - k)
                {
                    pq.pop();
                }
                res.push_back(pq.top().first);
            }
        }
        return res;
    }
};
// @lc code=end
