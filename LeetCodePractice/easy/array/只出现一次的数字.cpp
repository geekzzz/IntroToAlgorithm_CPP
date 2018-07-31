class Solution {
public:
	int singleNumber(vector<int>& nums) {
		map<int, int> m;
		for (auto it = nums.begin(); it < nums.end(); it++)
		{
			auto s = m.find(*it);
			if (s != m.end())
			{
				m.erase(s);
			}
			else
			{
				++m[*it];
			}
		}
		return m.begin()->first;
	}
};