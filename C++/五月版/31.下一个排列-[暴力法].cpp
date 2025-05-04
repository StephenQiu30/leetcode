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
        vector<int> original = nums;
        // 从最小排列开始
        sort(nums.begin(), nums.end());
        vector<vector<int>> permutations;
        do
        {
            permutations.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        for (int i = 0; i < permutations.size(); ++i)
        {
            if (permutations[i] == original)
            {
                if (i + 1 < permutations.size())
                {
                    // 下一个排列
                    nums = permutations[i + 1];
                }
                else
                {
                    // 已经是最大排列，返回最小的
                    nums = permutations[0];
                }
                return;
            }
        }
    }
};
// @lc code=end
