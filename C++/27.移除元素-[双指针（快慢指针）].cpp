/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素 [双指针（快慢指针）]
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        // 遍历数组：fast 从 0 到 nums.size() - 1。
        int slow = 0;
        for (int fast = 0; fast < n; fast++)
        {
            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        // 最终 slow 就是新数组的长度，nums 的前 slow 个元素即为结果
        return slow;
    }
};
// @lc code=end
