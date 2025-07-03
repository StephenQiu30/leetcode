/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数 [贪心]
 */

// @lc code=start
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        // layers[i] 表示长度为 i+1 的递增子序列结尾值及其数量
        vector<map<int, int>> layers;
        for (int num : nums)
        {
            int left = 0, right = layers.size();
            // 二分找最长层可以插入的位置
            while (left < right)
            {
                int mid = (left + right) / 2;
                auto it = layers[mid].rbegin();
                if (it != layers[mid].rend() && it->first < num)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }
            int count = 0;
            if (left == 0)
            {
                // 第一个数，长度为1
                count = 1;
            }
            else
            {
                for (auto &[key, val] : layers[left - 1])
                {
                    if (key < num)
                    {
                        count += val;
                    }
                }
            }

            if (left == layers.size())
            {
                layers.push_back({{num, count}});
            }
            else
            {
                layers[left][num] += count;
            }
        }
        // 累加最后一层所有序列的数量
        int res = 0;
        for (auto &[key, val] : layers.back())
        {
            res += val;
        }

        return res;
    }
};
// @lc code=end
