/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组 [滑动窗口]
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        int minLength = __INT_MAX__;
        int left, sum = 0;
        for (int right = 0; right < n; ++right)
        {
            sum += nums[right];
            while (sum >= target)
            {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return (minLength == __INT_MAX__) ? 0 : minLength;
    }
};
// @lc code=end
