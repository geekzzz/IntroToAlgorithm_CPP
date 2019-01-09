class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		std::sort(candidates.begin(), candidates.end());
		vector<int> combination;
		vector<vector<int>> result;
		traceBack(candidates, target, result, combination, 0);
		return result;
	}
	void traceBack(vector<int>& candidates, int target, vector<vector<int>> &result, vector<int> &combination, int begin)
	{
		if (!target)
		{
			result.push_back(combination);
			return;
		}
		for (int i = begin; i < candidates.size() && target >= candidates[i]; ++i)
		{
			combination.push_back(candidates[i]);
			traceBack(candidates, target - candidates[i], result, combination, i);
			combination.pop_back();
		}
	}
};