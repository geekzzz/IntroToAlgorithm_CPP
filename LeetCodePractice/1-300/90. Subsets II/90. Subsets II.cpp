class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> combine;
		sort(nums.begin(), nums.end());
		backtrack(res, combine, nums, 0);
		return res;
	}
	void backtrack(vector<vector<int>> & res, vector<int> & combine, vector<int> nums, int start)
	{
		res.push_back(combine);
		for (int i = start; i < nums.size(); ++i)
		{
			if (i != start && nums[i] == nums[i - 1])
				continue;


			combine.push_back(nums[i]);
			backtrack(res, combine, nums, i + 1);
			combine.pop_back();


		}

	}
};