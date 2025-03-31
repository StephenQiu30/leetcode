/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和 [分治法]
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        return maxSubArrayDivideConquer(nums, 0, nums.size() - 1);
    }

private:
    int crossSum(vector<int> &nums, int left, int right, int mid)
    {
        long long leftSum = LLONG_MIN, rightSum = LLONG_MIN, sum = 0; //
        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }
        sum = 0;
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        return leftSum + rightSum;
    }

    int maxSubArrayDivideConquer(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }
        int mid = (left + right) / 2;
        long long leftMax = maxSubArrayDivideConquer(nums, left, mid);
        long long rightMax = maxSubArrayDivideConquer(nums, mid + 1, right);
        long long crossMax = crossSum(nums, left, right, mid);

        return static_cast<int>(max({leftMax, rightMax, crossMax}));
    }
};
// @lc code=end
