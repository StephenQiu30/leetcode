/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II [STL]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do
        {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return res;
    }
};
// @lc code=end
