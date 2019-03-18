class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> combine;
		int n = nums.size();
		vector<bool> used(nums.size(), false);//使用一个used来保存每位是否使用
		sort(nums.begin(), nums.end());
		backtrack(result, combine, nums, used);
		return result;
	}
	void backtrack(vector<vector<int>>& result, vector<int>& combine, vector<int>& nums, vector<bool>& used)
	{
		if (combine.size() == nums.size())
		{
			result.push_back(combine);
			return;
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			if (used[i] || i > 0 && nums[i] == nums[i - 1] && !used[i - 1])//跳过使用了的位以及重复的nums[i]和nums[i - 1]
				continue;
			used[i] = true;
			combine.push_back(nums[i]);
			backtrack(result, combine, nums, used);
			used[i] = false;
			combine.pop_back();
		}
	}
};