class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> combination;
		getSubset(result, combination, nums, 0);
		return result;
	}
	void getSubset(vector<vector<int>> &result, vector<int> &combination, vector<int>& nums, int begin)
	{
		result.push_back(combination);//注意压入result的条件
		for (int i = begin; i < nums.size(); ++i)
		{
			combination.push_back(nums[i]);
			getSubset(result, combination, nums, i + 1);
			combination.pop_back();
		}
	}
};