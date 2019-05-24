//��nsum ����4sum����ת��Ϊtwo sum���⣬Ȼ����begin��end ����ָ�������
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());//ע��Ҫsort
		return NSum(nums, 0, nums.size() - 1, target, 4);
	}
	vector<vector<int>> NSum(vector<int>&nums, int start, int end, int target, int N) {
		vector<vector<int>> result;
		if (end - start + 1 < N || nums[start] * N > target || nums[end] * N < target)
			return result;
		if (N == 2)
			return twoSum(nums, start, end, target);
		for (int i = start; i <end; i++)
		{
			if (i == start || nums[i] != nums[i - 1])//������ͬ��ֵ
			{
				int select = nums[i];
				vector<vector<int>> tmp = NSum(nums, i + 1, end, target - select, N - 1);
				for (auto x : tmp)
				{
					x.push_back(select);
					result.push_back(x);
				}
			}
		}
		return result;
	}
	vector<vector<int>> twoSum(vector<int>&nums, int start, int end, int target)
	{
		vector<vector<int>> result;
		while (start < end)
		{
			if (nums[start] + nums[end] > target)
				end--;
			else if (nums[start] + nums[end] < target)
				start++;
			else
			{
				vector<int> tmp;
				tmp.push_back(nums[start]);
				tmp.push_back(nums[end]);
				result.push_back(tmp);
				while (start < end - 1 && nums[start] == nums[start + 1]) start++;
				while (start + 1 < end && nums[end] == nums[end - 1]) end--;
				start++;
				end--;
			}
		}
		return result;
	}
};
