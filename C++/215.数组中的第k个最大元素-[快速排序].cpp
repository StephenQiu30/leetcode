/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素 [快速排序]
 */

// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int left = 0, right = nums.size() - 1;
        k = nums.size() - k;
        while (left <= right)
        {
            int pivotIndex = partition(nums, left, right);
            if (pivotIndex == k)
            {
                return nums[k];
            }
            else if (pivotIndex < k)
            {
                left = pivotIndex + 1;
            }
            else
            {
                right = pivotIndex - 1;
            }
        }
        return -1;
    }

private:
    int partition(vector<int> &nums, int left, int right)
    {
        // 选择最后一个元素作为 pivot
        int pivot = nums[right];
        // i 指向存放小于 pivot 的区域
        int i = left;
        for (int j = left; j < right; j++)
        {
            if (nums[j] <= pivot)
            {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }
};
// @lc code=end
