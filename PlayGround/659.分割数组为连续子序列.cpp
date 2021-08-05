/*
 * @lc app=leetcode.cn id=659 lang=cpp
 *
 * [659] 分割数组为连续子序列
 */

// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> need,freq;
        for(auto v : nums)
        {
            freq[v]++;
        }
        for(auto v : nums)
        {
            if(freq[v] == 0)
                continue;
            if(need[v] > 0)
            {
                freq[v]--;
                need[v]--;
                need[v + 1]++;
            }
            else if(freq[v] > 0 &&freq[v +1] > 0 &&freq[v+2] > 0 )
            {
                freq[v]--;
                freq[v + 1]--;
                freq[v+2]--;
                need[v + 3]++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

