class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		int n = nums.size();
		if (n < 4)
			return result;
		sort(nums.begin(), nums.end());
		for (int i = 0; i< n - 3; ++i)
		{
			if (i > 0 && nums[i - 1] == nums[i]) continue;
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break; \\注意这行
			if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue; \\注意这行
			for (int j = i + 1; j < n - 2; ++j)
			{
				if (j > i + 1 && nums[j - 1] == nums[j]) continue;
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;\\注意这行
				if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue; \\注意这行
				int left = j + 1;
				int right = n - 1;
				while (left < right)
				{
					int sum = nums[i] + nums[j] + nums[left] + nums[right];
					if (sum >target)
						right--;
					else if (sum < target)
						left++;
					else
					{
						result.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
						left++; \\注意这行
						right--; \\注意这行
						while (left < right && nums[left] == nums[left - 1])
							left++;
						while (left < right && nums[right] == nums[right + 1])
							right--;
					}
				}
			}
		}
		return result;
	}
};