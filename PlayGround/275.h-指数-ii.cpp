/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0;
        int r = citations.size() - 1;
        while(l <= r)
        {
            int m = (r - l)/2 + l;
            if(citations[m] >= citations.size() - m)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return citations.size() - l;
    }
};
// @lc code=end

