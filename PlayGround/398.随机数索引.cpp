/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */

// @lc code=start
class Solution {
public:
    unordered_map<int, vector<int>> m;

    Solution(vector<int>& nums) {
        for(int i = 0;i < nums.size();++i)
        {
            m[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        return m[target][rand() % ( m[target].size() )]  ;
        //rand() % (n + 1)
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

