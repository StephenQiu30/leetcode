/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数 [快慢指针]
 */

// @lc code=start
class Solution
{
public:
    bool isHappy(int n)
    {
        int slow = n, fast = getNext(n);
        while (fast != 1 && slow != fast)
        {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
    int getNext(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
};
// @lc code=end
