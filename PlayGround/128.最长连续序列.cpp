/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
//暴力
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size() == 0)
//             return 0;
//         int res = 1;
//         sort(nums.begin(),nums.end(),less<int>());
//         int start = 0;
//         int nowlong = 1;
//         for(int i = 0; i < nums.size() - 1;++i)
//         {
//             int cur = nums[i];
//             int aft = nums[i +1];
//             if(cur + 1 == aft )
//             {
//                 nowlong++;
//             }
//             else if(cur == aft)
//             {
//                 continue;
//             }
//             else 
//             {
                
//                 res = max(nowlong,res);
//                 nowlong = 1;
//             }
//         }
//          res = max(nowlong,res);
//         return res;
//     }
// };
//
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
       unordered_set<int> s;
       for(auto n : nums)
       {
           s.insert(n);
       }
        
        for(int i = 0;i < nums.size();++i)
        {
            int cur = nums[i];
            if(s.count(cur - 1) > 0)
            {
                continue;
            }
            int nowlong = 1;
            while(s.count(cur + 1))
            {
                cur++;
                nowlong++;
            }
            res = max(nowlong,res);
        }
        return res;
    }
};
// @lc code=end

