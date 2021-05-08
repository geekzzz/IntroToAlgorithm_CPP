/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        else if (n == 1)
            return nums[0];
        auto r1 = helper(nums,0,n - 1);
        auto r2 = helper(nums,1,n);
        return max(r1,r2);

    }
    int helper(vector<int>& nums,int left,int right)
    {
        if(right - left <= 1)
            return nums[left];
        vector<int> dp(right, 0);
        dp[left] = nums[left];
        dp[left + 1] = max(nums[left],nums[left + 1]);
        for(int i = left + 2;i < right;++i)
        {
            dp[i] = max(dp[i - 1],dp[i - 2] + nums[i] );
        }
        return dp[right - 1];
    }
};
// @lc code=end

