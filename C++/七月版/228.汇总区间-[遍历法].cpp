/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间 [遍历法]
 */

// @lc code=start
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> result;
        int n = nums.size();
        for (int i = 0; i < n;)
        {
            int start = i;
            while (i + 1 < n && nums[i + 1] == nums[i] + 1)
            {
                i++;
            }
            if (start == i)
            {
                result.emplace_back(to_string(nums[start]));
            }
            else
            {
                result.emplace_back(to_string(nums[start]) + "->" + to_string(nums[i]));
            }
            i++;
        }
        return result;
    }
};
// @lc code=end
