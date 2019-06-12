class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX,big = INT_MAX;
        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i] <= small)
                small = nums[i];
            else if(nums[i] <= big)
                big = nums[i];
            else
                return true;
        }
        return false;
    }
};
