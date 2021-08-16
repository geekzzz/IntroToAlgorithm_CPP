/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
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
        //sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i = start;i < nums.size();++i)
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

    vector<vector<int>> fourSumtarget(vector<int>& nums, int start,int target)
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i = 0;i < nums.size();++i)
        {
            auto t = threeSumtarget(nums,i + 1,target - nums[i]);
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

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return fourSumtarget(nums,0,target);
    }
};
// @lc code=end

