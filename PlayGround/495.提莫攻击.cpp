/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        int lastduto = 0;
        if(timeSeries.size() == 0)
            return 0;
        for(int i = 1; i < timeSeries.size();++i)
        {
            int diff = timeSeries[i] - timeSeries[i -1];
            res += min(diff, duration);
        }
        return res + duration;
    }
};
// @lc code=end

