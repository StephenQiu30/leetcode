/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积 [空间优化版]
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> answer(n, 1);
        for (int i = 1; i < n; i++)
        {
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        int R = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            answer[i] *= R;
            R *= nums[i];
        }

        return answer;
    }
};
// @lc code=end
