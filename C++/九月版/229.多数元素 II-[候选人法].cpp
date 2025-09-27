/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 多数元素 II [候选人法]
 */

// @lc code=start
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res;
        if (n == 0)
        {
            return res;
        }
        // 初始化为不同值以避免一开始相等带来的分歧
        int cand1 = 0, cand2 = 1;
        int count1 = 0, count2 = 0;
        for (int x : nums)
        {
            if (x == cand1)
            {
                count1++;
            }
            else if (x == cand2)
            {
                count2++;
            }

            else if (count1 == 0)
            {
                cand1 = x;
                count1 = 1;
            }
            else if (count2 == 0)
            {
                cand2 = x;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        // 第二遍：验证候选人
        count1 = count2 = 0;
        for (int x : nums)
        {
            if (x == cand1)
            {
                ++count1;
            }
            else if (x == cand2)
            {
                ++count2;
            }
        }
        int threshold = n / 3;
        if (count1 > threshold)
        {
            res.push_back(cand1);
        }
        if (count2 > threshold)
        {
            res.push_back(cand2);
        }
        return res;
    }
};
// @lc code=end
