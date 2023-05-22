/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);
        for (int i= 0; i < trips.size();++i)
        {
            
            int count = trips[i][0];
            int start = trips[i][1];
            int end = trips[i][2];
            diff[start] += count;
            diff[end] -= count;
        }
        int current = 0;
        for (int i = 0; i < diff.size(); ++i)
        {
            current += diff[i];
            if (current > capacity)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

