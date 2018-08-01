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


//第二种解法
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			ans ^= nums[i];
		}
		return ans;
	}
};