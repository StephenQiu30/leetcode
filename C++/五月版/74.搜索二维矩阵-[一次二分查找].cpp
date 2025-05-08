/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵 [一次二分查找]
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int midVal = matrix[mid / n][mid % n];
            if (midVal == target)
            {
                return true;
            }
            else if (midVal < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end
