/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II [双指针]
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
        {
            return n;
        }
        int slow = 2;
        for (int fast = 2; fast < n; fast++)
        {
            if (nums[fast] != nums[slow - 2])
            {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};
// @lc code=end
