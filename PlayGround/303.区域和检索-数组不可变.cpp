/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:

    vector<int> sum;
    NumArray(vector<int>& nums) {
        int total = 0;
        sum.push_back(0);
        for(int i = 0; i < nums.size(); ++i)
        {
            total += nums[i];
            sum.push_back(total);
        }
    }
    
    int sumRange(int left, int right) {
        return sum[right + 1] - sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

