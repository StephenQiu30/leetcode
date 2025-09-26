/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II [直接排序]
 */

// @lc code=start
class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return;
        vector<int> a = nums;
        sort(a.begin(), a.end());
        vector<int> res(n);
        // 左半段长度
        int mid = (n + 1) / 2;
        // 左半段的末尾索引
        int left = mid - 1;
        // 右半段的末尾索引
        int right = n - 1;
        for (int i = 0; i < n; ++i)
        {
            if ((i & 1) == 0)
            {
                // 偶数位置放左半段的最大剩余
                res[i] = a[left--];
            }
            else
            {
                // 奇数位置放右半段的最大剩余
                res[i] = a[right--];
            }
        }
        nums.swap(res);
    }
};
// @lc code=end
