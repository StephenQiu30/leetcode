/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
class RandomizedSet
{
private:
    // 记录 val -> index
    unordered_map<int, int> valueToIndex;
    // 存储元素的数组
    vector<int> nums;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (valueToIndex.count(val))
        {
            return false;
        }
        nums.push_back(val);
        valueToIndex[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (!valueToIndex.count(val))
        {
            return false;
        }
        int index = valueToIndex[val];
        int lastVal = nums.back();
        nums[index] = lastVal;
        valueToIndex[lastVal] = index;
        nums.pop_back();
        valueToIndex.erase(val);
        return true;
    }

    int getRandom()
    {
        int randIndex = rand() % nums.size();
        return nums[randIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
