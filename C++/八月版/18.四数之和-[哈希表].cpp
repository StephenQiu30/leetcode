/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和 [哈希表]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4)
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                long long target2 = (long long)target - nums[i] - nums[j];
                unordered_set<long long> seen;
                for (int k = j + 1; k < n; k++)
                {
                    long long need = target2 - nums[k];
                    if (seen.count(need))
                    {
                        st.insert({nums[i], nums[j], (int)need, nums[k]});
                    }
                    seen.insert(nums[k]);
                }
            }
        }
        res.assign(st.begin(), st.end());
        return res;
    }
};
// @lc code=end
