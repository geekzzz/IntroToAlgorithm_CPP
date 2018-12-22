class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		vector<int> result;
		for (int i = 0; i < nums.size(); ++i)
		{
			int need = target - nums[i];
			if (m.find(need) != m.end())
			{
				result.push_back(m[need]);
				result.push_back(i);
				return result;
			}
			m[nums[i]] = i;
		}
		return result;
	}
};