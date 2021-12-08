/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 *
 * [1288] 删除被覆盖区间
 */

// @lc code=start

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) 
    {
        if(a[0] != b[0])
            return a[0] < b[0];
        else
            return a[1] > b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        for (auto it = intervals.begin(); it != intervals.end(); ++it)
        {
            int p = (*it)[1];
            auto curit = it + 1;
            while (curit != intervals.end() && (*curit)[1] <= p)
            {
                curit = intervals.erase(curit);
            }
        }
        return intervals.size();
    }
};
// @lc code=end

