/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II [扩展法]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result = {{}};
        // 排序确保相同元素相邻
        sort(nums.begin(), nums.end());
        // 记录上一次新加入子集的起始位置
        int prevSize = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // 记录当前已有子集的数量
            int size = result.size();
            // 处理重复元素
            int startIndex = (i > 0 && nums[i] == nums[i - 1]) ? prevSize : 0;
            // 记录当前层新增子集的起始位置
            prevSize = size;

            for (int j = startIndex; j < size; j++)
            {
                vector<int> newSubset = result[j];
                newSubset.push_back(nums[i]);
                result.push_back(newSubset);
            }
        }
        return result;
    }
};
// @lc code=end
