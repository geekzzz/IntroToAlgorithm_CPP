class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		if (digits.empty())
			return result;
		vector<string> ss{ "0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		result.push_back("");
		for (int i = 0; i < digits.size(); ++i)
		{
			string s = ss[digits[i] - '0'];
			vector<string> tmp;
			for (int j = 0; j < s.size(); ++j)
			{
				for (int k = 0; k < result.size(); ++k)
				{
					tmp.push_back(result[k] + s[j]);
				}
			}
			result = tmp;
		}
		return result;
	}
};