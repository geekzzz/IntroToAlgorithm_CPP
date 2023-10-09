/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int child = 0;
        int cookie = 0;
        while(child < g.size() && cookie < s.size())
        {
            if(g[child] <= s[cookie])
            {
                child++;
            }
            cookie++;
        }
        return child;
    }
};
// @lc code=end

