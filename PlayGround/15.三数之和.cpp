/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3)
            return res;
        sort(nums.begin(),nums.end());
        if(nums[0] > 0)
            return res;
       
        int i = 0;
        while(i < nums.size())
        {


            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k)
            {
                if( nums[j] + nums[k] == -nums[i]  )
                {
                    // vector<int> r;
                    // r.push_back(nums[i]);
                    // r.push_back(nums[j]);
                    // r.push_back(nums[k]);
                    res.push_back(vector<int>{nums[i],nums[j],nums[k]} );
                    
                    while(j < k && nums[j] == nums[j + 1])
                    {
                        j++;
                    }
                    while(j < k && nums[k] == nums[k - 1])
                    {
                        k--;
                    }
                    j++;
                    k--;
                }
                else 
                {
                    if(nums[j] + nums[k] > -nums[i])
                    {
                        k--;
                    }
                    else if(nums[j] + nums[k] < -nums[i])
                    {
                        j++;
                    }
                }
            }
            while(i < nums.size() - 1 && nums[i] == nums[i + 1] )
            {
                i++;
            }
            i++;
        }
            
        return res;
    }
};
// @lc code=end

