class Solution {
public:
	bool isAnagram(string s, string t) {
		map<char, int> m;

		if (t.length() < s.length())
		{
			return false;
		}
		for (int i = 0; i < s.length(); ++i)
		{
			++m[s[i]];
		}
		for (int i = 0; i < t.length(); ++i)
		{
			if (m.find(t[i]) == m.end() || m.find(t[i])->second == 0)
			{
				return false;
			}
			else
			{
				--(m.find(t[i])->second);
			}
		}
		return true;
	}
};