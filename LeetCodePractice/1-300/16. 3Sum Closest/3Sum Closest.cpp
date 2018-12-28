class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int result = 0;
		std::sort(nums.begin(), nums.end());//注意！！！！！和15题一样，一定要sort
		if (nums.size() <= 3)
		{
			for (int i = 0; i < nums.size(); ++i)
				result += nums[i];
			return result;
		}
		result = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < nums.size() - 2; ++i)
		{
			int j = i + 1;
			int k = nums.size() - 1;
			while (j < k)
			{
				int sums = nums[i] + nums[j] + nums[k];
				if (abs(target - result) >  abs(target - sums))
				{
					result = sums;
					if (result == target)
						return result;
				}
				(sums > target) ? k-- : j++;
			}
		}
		return result;
	}

};


