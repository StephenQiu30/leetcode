/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素 [小根堆]
 */

// @lc code=start
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        // 小顶堆，存储 {值, 行号, 列号}
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        // 初始化：每一行的第一个元素入堆
        for (int i = 0; i < n; i++)
        {
            pq.emplace(matrix[i][0], i, 0);
        }
        // 弹出 k-1 次
        for (int i = 1; i < k; i++)
        {
            auto [value, row, col] = pq.top();
            pq.pop();
            // 如果当前元素所在行还有下一个元素，则入堆
            if (col + 1 < n)
            {
                pq.emplace(matrix[row][col + 1], row, col + 1);
            }
        }
        // 堆顶元素的值
        return get<0>(pq.top());
    }
};
// @lc code=end
