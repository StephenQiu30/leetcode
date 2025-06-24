/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站 [暴力法]
 */

// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        for (int start = 0; start < n; start++)
        {
            int tank = 0;
            int count = 0;
            while (count < n)
            {
                int index = (start + count) % n;
                tank += gas[index] - cost[index];
                if (tank < 0)
                {
                    break;
                }
                ++count;
            }
            if (count == n)
            {
                return start;
            }
        }
        return -1;
    }
};
// @lc code=end
