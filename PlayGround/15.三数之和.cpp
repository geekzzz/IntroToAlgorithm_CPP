/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> res;
//         if(nums.size() < 3)
//             return res;
//         sort(nums.begin(),nums.end());
//         if(nums[0] > 0)
//             return res;
       
//         int i = 0;
//         while(i < nums.size())
//         {


//             int j = i + 1;
//             int k = nums.size() - 1;
//             while(j < k)
//             {
//                 if( nums[j] + nums[k] == -nums[i]  )
//                 {
//                     // vector<int> r;
//                     // r.push_back(nums[i]);
//                     // r.push_back(nums[j]);
//                     // r.push_back(nums[k]);
//                     res.push_back(vector<int>{nums[i],nums[j],nums[k]} );
                    
//                     while(j < k && nums[j] == nums[j + 1])
//                     {
//                         j++;
//                     }
//                     while(j < k && nums[k] == nums[k - 1])
//                     {
//                         k--;
//                     }
//                     j++;
//                     k--;
//                 }
//                 else 
//                 {
//                     if(nums[j] + nums[k] > -nums[i])
//                     {
//                         k--;
//                     }
//                     else if(nums[j] + nums[k] < -nums[i])
//                     {
//                         j++;
//                     }
//                 }
//             }
//             while(i < nums.size() - 1 && nums[i] == nums[i + 1] )
//             {
//                 i++;
//             }
//             i++;
//         }
            
//         return res;
//     }
// };
class Solution {
public:
    vector<vector<int>> twosumtarget(vector<int>& nums, int start,int target)
    {
        vector<vector<int>>  res;
        int l = start;
        int r = nums.size() - 1;
        while(l < r)
        {
            int low = nums[l];
            int high = nums[r];
            if(low + high < target)
            {
                //l++;
                while(l < r &&  low == nums[l])
                    l++;
            }
            else if(low + high > target)
            {
                while(l < r &&   high == nums[r])
                    r--;
            }
            else
            {
                vector<int> rr{nums[l],nums[r]};
                while (l < r && low == nums[l])
                l++;
            while (l < r && high == nums[r])
                r--;
                res.push_back(rr);
            }
        }
        return res;
    }

    vector<vector<int>> threeSumtarget(vector<int>& nums, int start,int target)
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i = 0;i < nums.size();++i)
        {
            auto t = twosumtarget(nums,i + 1,target - nums[i]);
            for(auto x : t)
            {
                x.push_back(nums[i]);
                res.push_back(x);
            }
            while(i < nums.size() - 1 && nums[i] == nums[i + 1] )
                i++;
        }
        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        return threeSumtarget(nums,0,0);
    }
};
// @lc code=end

