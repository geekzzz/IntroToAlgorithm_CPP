class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		vector<string> combine;
		backtrack(s, res, combine, 0);
		return res;
	}
	void backtrack(string s, vector<string> & res, vector<string> & combine, int start)
	{
		if (start >= s.size() || start > 12)
		{
			if (combine.size() == 4)
			{
				string t;
				for (int i = 0; i < 3; ++i)
					t += combine[i] + '.';
				t += combine[3];
				res.push_back(t);
			}
			return;
		}
		for (int i = start; i < start + 3 && i < s.size(); ++i)
		{

			string tmp = s.substr(start, i - start + 1);

			if (tmp[0] == '0' && start != i)
				continue;
			if (stoi(tmp) >= 0 && stoi(tmp) <= 255)
			{
				combine.push_back(tmp);
				backtrack(s, res, combine, i + 1);
				combine.pop_back();
			}
		}
	}
};