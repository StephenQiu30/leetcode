/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字 [排序法]
 */

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i)
            {
                return i;
            }
        }
        return nums.size();
    }
};
// @lc code=end
