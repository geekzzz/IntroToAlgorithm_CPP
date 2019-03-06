class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		sort(people.begin(), people.end(), [](const pair<int, int> & a, const pair<int, int> & b) {return (a.first > b.first || (a.first == b.first && a.second < b.second)); });
		vector<pair<int, int>> result;
		for (auto p : people)
		{
			result.insert(result.begin() + p.second, p);
		}
		return result;
	}
};