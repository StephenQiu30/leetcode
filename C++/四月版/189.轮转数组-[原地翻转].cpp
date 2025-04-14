/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组 [原地翻转]
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        reviese(nums, 0, n - 1);
        reviese(nums, 0, k - 1);
        reviese(nums, k, n - 1);
    }

private:
    void reviese(vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            swap(nums[start++], nums[end--]);
        }
    }
};
// @lc code=end
