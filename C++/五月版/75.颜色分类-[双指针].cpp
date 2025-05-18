/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类 [双指针]
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        int i = 0;
        while (i <= right)
        {
            if (nums[i] == 0)
            {
                swap(nums[i++], nums[left++]);
            }
            else if (nums[i] == 2)
            {
                swap(nums[i], nums[right--]);
            }
            else
            {
                i++;
            }
        }
    }
};
// @lc code=end
