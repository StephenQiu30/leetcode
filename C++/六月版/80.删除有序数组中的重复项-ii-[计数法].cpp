/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II [计数法]
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
        int index = 1, count = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            if (count <= 2)
            {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};
// @lc code=end
