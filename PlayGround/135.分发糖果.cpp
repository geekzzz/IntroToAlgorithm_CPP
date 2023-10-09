/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> nums(ratings.size(), 1);
        int res = 0;
        for(int i = 1; i < ratings.size();++i)
        {
            if(ratings[i] > ratings[i - 1])
                nums[i] = nums[i - 1] + 1;
        }
        for(int i = ratings.size() - 2; i >= 0; --i)
        {
            if(ratings[i] > ratings[i + 1])
                nums[i] = max(nums[i] , nums[i + 1] + 1);
        }
        for(int i = 0;i < nums.size();++i)
        {
            res += nums[i];
        }
        return res;
    }
};
// @lc code=end

