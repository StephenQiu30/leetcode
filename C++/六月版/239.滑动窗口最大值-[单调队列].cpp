/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值 [单调队列]
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            // 移除窗口外的元素
            if (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }
            // 维护队列单调递减
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            // 记录结果
            if (i >= k - 1)
            {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
// @lc code=end
