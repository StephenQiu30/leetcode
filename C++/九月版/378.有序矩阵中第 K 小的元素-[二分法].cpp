/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素 [二分法]
 */

// @lc code=start
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size(), m = matrix[0].size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];
        auto countLE = [&](int x) -> int
        {
            int i = n - 1, j = 0, count = 0;
            while (i >= 0 && j < n)
            {
                if (matrix[i][j] <= x)
                {
                    count += i + 1;
                    j++;
                }
                else
                {
                    i--;
                }
            }
            return count;
        };
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (countLE(mid) >= k)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
// @lc code=end
