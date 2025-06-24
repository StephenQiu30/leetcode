/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站 [贪心算法]
 */

// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total = 0, tank = 0, start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;
            if (tank < 0)
            {
                start = i + 1;
                tank = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
};
// @lc code=end
