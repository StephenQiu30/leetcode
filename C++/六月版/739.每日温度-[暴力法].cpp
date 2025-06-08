/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (temperatures[j] > temperatures[i])
                {
                    answer[i] = j - i;
                    break;
                }
            }
        }
        return answer;
    }
};
// @lc code=end
