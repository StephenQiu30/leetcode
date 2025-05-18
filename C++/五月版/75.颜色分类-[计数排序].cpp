/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类 [计数排序]
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int count0 = 0, count1 = 0, count2 = 0;
        for (int num : nums)
        {
            if (num == 0)
            {
                count0++;
            }
            else if (num == 1)
            {
                count1++;
            }
            else
            {
                count2++;
            }
        }
        int index = 0;
        while (count0--)
        {
            nums[index++] = 0;
        }
        while (count1--)
        {
            nums[index++] = 1;
        }
        while (count2--)
        {
            nums[index++] = 2;
        }
    }
};
// @lc code=end
