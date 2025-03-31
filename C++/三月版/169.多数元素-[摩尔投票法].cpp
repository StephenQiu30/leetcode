/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素 [摩尔投票法]
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = -1;
        int count = 0;

        for (int num : nums)
        {
            if (count == 0)
            {
                candidate = num;
                count = 1;
            }
            else if (num == candidate)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return candidate;
    }
};
// @lc code=end
