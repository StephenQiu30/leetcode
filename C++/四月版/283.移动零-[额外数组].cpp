/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零 [额外数组]
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        vector<int> temp;
        // 1. 遍历数组，收集所有非零元素
        for (int num : nums)
        {
            if (num != 0)
            {
                temp.push_back(num);
            }
        }
        // 2. 将非零元素拷贝回 nums
        int zeroSize = temp.size();
        for (int i = 0; i < zeroSize; i++)
        {
            nums[i] = temp[i];
        }
        // 3. 在剩余的位置填充 0
        for (int i = zeroSize; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};
// @lc code=end
