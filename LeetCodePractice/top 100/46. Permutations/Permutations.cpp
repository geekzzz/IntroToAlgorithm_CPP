class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> combination;
		getPer(result, combination, nums);
		return result;
	}
	void getPer(vector<vector<int>>& result, vector<int> & combination, vector<int>& nums)
	{
		if (combination.size() == nums.size())
		{
			result.push_back(combination);
			return;
		}
		for (int i = 0; i < nums.size(); ++i)
		{

			if (find(combination.begin(), combination.end(), nums[i]) != combination.end())
				continue;
			combination.push_back(nums[i]);
			getPer(result, combination, nums);
			combination.pop_back();
		}
	}
};