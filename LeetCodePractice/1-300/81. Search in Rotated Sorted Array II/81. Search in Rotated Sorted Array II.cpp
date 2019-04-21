class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        int num;
        while(low <= high)
        {
            mid = (low + high) /2;
            if(nums[mid] == target)
                return true;
            if(nums[low] == nums[mid] && nums[high] == nums[mid])
            {
                low++;
                high--;
            }
            else if(nums[low] <= nums[mid])
            {
                if(nums[low] <= target && nums[mid] > target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if(nums[mid] < target && nums[high] >= target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};
