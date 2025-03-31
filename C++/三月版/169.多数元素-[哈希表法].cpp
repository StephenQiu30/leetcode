/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素 [哈希表法]
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> map;
        int mid = nums.size() / 2;
        for (int num : nums)
        {
            map[num]++;
            if (map[num] > mid)
            {
                return num;
            }
        }
        return -1;
    }
};
// @lc code=end
