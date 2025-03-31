/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字 [哈希表法]
 */

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i <= n; i++)
        {
            if (numSet.find(i) == numSet.end())
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
