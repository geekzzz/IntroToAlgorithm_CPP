/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        if (a[0] != b[0])
            return a[0] < b[0];
        else
            return a[1] < b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i = 1;i < intervals.size();++i)
        {
            const auto& t = intervals[i];
            if( t[0] <= res.back()[1])
            {
                res.back()[1] = max(res.back()[1] , t[1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
// @lc code=end

