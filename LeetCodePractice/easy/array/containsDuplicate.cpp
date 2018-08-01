class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() < 2)
		{
			return false;
		}
		map<int, int> m;
		for (auto it = nums.begin(); it != nums.end(); it++)
		{
			if (m.find(*it) != m.end())
			{
				return true;
			}
			++m[*it];
		}
		return false;
	}
};