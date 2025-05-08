/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵 [两次二分查找]
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        // 第一步：定位所在行
        int top = 0, bottom = m - 1;
        while (top <= bottom)
        {
            int mid = (top + bottom) / 2;
            if (matrix[mid][0] > target)
            {
                bottom = mid - 1;
            }
            else if (matrix[mid][n - 1] < target)
            {
                top = mid + 1;
            }
            else
            {
                int left = 0, right = n - 1;
                while (left <= right)
                {
                    int midIndex = (left + right) / 2;
                    if (matrix[mid][midIndex] == target)
                    {
                        return true;
                    }
                    else if (matrix[mid][midIndex] < target)
                    {
                        left = midIndex + 1;
                    }
                    else if (matrix[mid][midIndex] > target)
                    {
                        right = midIndex - 1;
                    }
                }
                return false;
            }
        }
        return false;
    }
};
// @lc code=end
