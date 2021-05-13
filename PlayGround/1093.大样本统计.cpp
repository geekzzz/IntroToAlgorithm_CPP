/*
 * @lc app=leetcode.cn id=1093 lang=cpp
 *
 * [1093] 大样本统计
 */

// @lc code=start
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int minres = INT_MAX;
        int maxrespos = -1;
        int maxres = INT_MIN;
        int minrespos = -1;
        long long total = 0;
        unordered_map<int,int> m;
        for(int i = 0;i < count.size();++i)
        {
            // total += count[i];
            // minres = min(minres,count[i]);
            // maxres = max(maxres,count[i]);
            // m[]
            if(count[i] > maxres)
            {
                maxres = count[i];
                maxrespos = i;
            }
            
            // if(count[i] >0 && count[i] < minres)
            // {
            //     minres = count[i];
            //     minrespos = i;
            // }
        }
    }
};
// @lc code=end

