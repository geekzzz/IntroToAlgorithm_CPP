/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r)
        {
            int m = l + (r - l)/2;
            if(nums[m] > target)
                r = m - 1;
            else if(nums[m] < target)
                l = m + 1;
            else if(nums[m] == target)
                return m;
        }
        return -1;
    }
};
// @lc code=end

