class Solution {
public:
	static bool cmp(const vector<int>&a, const vector<int>&b)
	{
		return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
	}
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(), cmp);
		vector<vector<int>> res;
		for (int i = 0; i < people.size(); ++i)
		{
			res.insert(res.begin() + people[i][1], people[i]);
		}
		return res;
	}
};