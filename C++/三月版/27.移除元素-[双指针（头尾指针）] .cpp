/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素 [双指针（头尾指针）]
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left <= right)
        {
            if (nums[left] == val)
            {
                nums[left] = nums[right];
                right--;
            }
            else
            {
                left++;
            }
        }
        return left;
    }
};
// @lc code=end
