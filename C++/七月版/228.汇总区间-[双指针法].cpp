/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间 [双指针法]
 */

// @lc code=start
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> result;
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            int start = i;
            while (i + 1 < n && nums[i + 1] == nums[i] + 1)
            {
                i++;
            }
            if (i > start)
            {
                result.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
            }
            else
            {
                result.push_back(to_string(nums[start]));
            }
            i++;
        }
        return result;
    }
};
// @lc code=end
