/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        int l = 0, r = nums.size() - 1;
        while(l <= r)
        {
            int m = l + (r - l)/2;
            if(nums[m] < target)
                l = m + 1;
            else if(nums[m] > target)
                r = m - 1;
            else if(nums[m] == target)
                r = m - 1;
        }
        if(l >= nums.size() || nums[l] != target)
            return res;
        else 
            res[0] = l;
        l = 0;
        r = nums.size() - 1;
        while(l <= r)
        {
            int m = l + (r - l)/2;
            if(nums[m] < target)
                l = m + 1;
            else if(nums[m] > target)
                r = m - 1;
            else if(nums[m] == target)
                l = m + 1;
        }
        res[1] = r;
        return res;
    }
};
// @lc code=end

