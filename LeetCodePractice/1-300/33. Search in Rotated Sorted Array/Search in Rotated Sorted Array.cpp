class Solution {
public:
	int search(vector<int>& nums, int target) {
		int low = 0, high = nums.size() - 1;
		int mid;
		int num;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if ((nums[mid] < nums[0]) == (target < nums[0]))
				num = nums[mid];
			else
				num = nums[0] < target ? INT_MAX : INT_MIN;
			if (num < target)
				low = mid + 1;
			else if (num > target)
				high = mid - 1;
			else
				return mid;
		}
		return -1;
	}
};