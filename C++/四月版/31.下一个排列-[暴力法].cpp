/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        vector<vector<int>> perms;
        sort(nums.begin(), nums.end());
        do
        {
            perms.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        for (int i = 0; i < perms.size(); i++)
        {
            if (perms[i] == nums && i + 1 < perms.size())
            {
                nums = perms[i + 1];
                return;
            }
        }
        nums = perms[0];
    }
};
// @lc code=end
