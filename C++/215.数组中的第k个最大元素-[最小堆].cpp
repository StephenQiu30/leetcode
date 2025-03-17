/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素 [最小堆]
 */

// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums)
        {
            minHeap.push(num);
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
// @lc code=end
