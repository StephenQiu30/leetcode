/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组 [哈希表法]
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int sum = 0, count = 0;
        for (int num : nums)
        {
            sum += num;
            if (prefixCount.count(sum - k))
            {
                count += prefixCount[sum - k];
            }
            prefixCount[sum]++;
        }
        return count;
    }
};
// @lc code=end
