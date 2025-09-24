/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距 [基数排序]
 */

// @lc code=start
class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return 0;
        }
        // 基数排序：按 16 位一段，需 2 次（32 位覆盖）
        const int B = 1 << 16; // 65536
        vector<int> aux(n);
        vector<int> cnt(B);

        // 两次按 16 位进行稳定计数排序
        for (int shift = 0; shift < 32; shift += 16)
        {
            fill(cnt.begin(), cnt.end(), 0);
            for (int x : nums)
            {
                cnt[(x >> shift) & 0xFFFF]++;
            }
            for (int i = 1; i < B; ++i)
            {
                cnt[i] += cnt[i - 1];
            }
            for (int i = n - 1; i >= 0; --i)
            {
                int key = (nums[i] >> shift) & 0xFFFF;
                aux[--cnt[key]] = nums[i];
            }
            nums.swap(aux);
        }

        int ans = 0;
        for (int i = 1; i < n; ++i)
        {
            ans = max(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }
};
// @lc code=end
