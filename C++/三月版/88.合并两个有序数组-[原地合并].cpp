/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组 [双指针从前向后合并（额外空间）]
 */

// @lc code=start
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> result(m + n);
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                result[k++] = nums1[i++];
            }
            else
            {
                result[k++] = nums2[j++];
            }
        }
        while (i < m)
        {
            result[k++] = nums1[i++];
        }
        while (j < n)
        {
            result[k++] = nums2[j++];
        }
        for (int i = 0; i < m + n; i++)
        {
            nums1[i] = result[i];
        }
    }
};
// @lc code=end
