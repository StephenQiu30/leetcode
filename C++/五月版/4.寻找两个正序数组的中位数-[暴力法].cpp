/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                merged.push_back(nums1[i++]);
            }
            else
            {
                merged.push_back(nums2[j++]);
            }
        }
        while (i < nums1.size())
        {
            merged.push_back(nums1[i++]);
        }
        while (j < nums2.size())
        {
            merged.push_back(nums2[j++]);
        }
        int n = merged.size();
        if (n % 2 == 1)
        {
            return merged[n / 2];
        }
        else
        {
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        }
    }
};
// @lc code=end
