/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int start = 0;
        int end = 0;
        while (start < nums.size())
        {
            end = start;
            while (end < nums.size() && end + 1 < nums.size() &&  nums[end] + 1 == nums[end + 1] )
            {
                end++;
            }
            string curres;
            if (end != start)
                curres = to_string(nums[start]) + "->" + to_string(nums[end]);
            else
                curres = to_string(nums[start]);
            
            res.push_back(curres);
            start = end + 1;
        }
        return res;
    }
};
// @lc code=end

