class Solution {
public:
	vector<int> topKFrequent(vector<int> &nums, int k)
	{
		vector<int> res;
		vector<vector<int>> bucket(nums.size() + 1);
		unordered_map<int, int> m;
		for (auto x : nums)
			m[x]++;
		for (auto it = m.begin(); it != m.end(); ++it)
		{
			bucket[it->second].push_back(it->first);
		}
		for (int i = bucket.size() - 1; i > 0; --i)
		{
			if (!bucket[i].empty())
			{
				for (int j = 0; j < bucket[i].size(); ++j)
				{
					res.push_back(bucket[i][j]);
					if (res.size() >= k)
						return res;
				}
			}
		}
		return res;
	}
};