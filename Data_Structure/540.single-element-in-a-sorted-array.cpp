/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int res = nums[0];
        for(int i = 1;i < nums.size();++i)
        {
            res ^= nums[i];
        }
        return res;
    }
};

