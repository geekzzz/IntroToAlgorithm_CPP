class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> combine;
		backtrack(result, combine, s, 0);
		return result;
	}
	void backtrack(vector<vector<string>>& result, vector<string>& combine, string s, int start)
	{
		if (start >= s.size())
		{
			result.push_back(combine);
			return;
		}
		for (int i = start; i < s.size(); ++i)
		{
			string tmp = s.substr(start, i - start + 1);
			if (ispalindrome(tmp))
			{
				combine.push_back(tmp);
				backtrack(result, combine, s, i + 1);
				combine.pop_back();
			}
		}
	}
	bool ispalindrome(string tmp)
	{
		int i = 0, j = tmp.size() - 1;
		while (i <= j)
		{
			if (tmp[i++] != tmp[j--])
				return false;
		}
		return true;
	}
};