/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列 [回溯法]
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> result;
        backtrack(result, nums, 0, n);
        return result;
    }

private:
    void backtrack(vector<vector<int>> &result, vector<int> &output, int first, int length)
    {
        if (first == length)
        {
            result.emplace_back(output);
            return;
        }
        for (int i = first; i < length; i++)
        {
            swap(output[i], output[first]);
            backtrack(result, output, first + 1, length);
            swap(output[i], output[first]);
        }
    }
    void backtrack(vector<vector<int>> &result, vector<int> &output, int first)
    {
        // 递归的终止条件
        if (first == output.size())
        {
            // 记录当前排列
            result.emplace_back(output);
            return;
        }
        // 遍历可选数字
        for (int i = first; i < output.size(); i++)
        {
            // 仅在需要时交换
            if (i != first)
                swap(output[i], output[first]);
            backtrack(result, output, first + 1);
            // 回溯
            if (i != first)
                swap(output[i], output[first]);
        }
    }
};
// @lc code=end
