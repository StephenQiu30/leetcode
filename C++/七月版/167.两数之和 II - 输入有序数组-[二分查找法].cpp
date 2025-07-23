/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组 [二分查找法]
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        for (int i = 0; i < numbers.size(); i++)
        {
            int left = i + 1, right = numbers.size() - 1;
            int complement = target - numbers[i];
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (numbers[mid] == complement)
                {
                    return {i + 1, mid + 1};
                }
                else if (numbers[mid] < complement)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return {};
    }
};
// @lc code=end
