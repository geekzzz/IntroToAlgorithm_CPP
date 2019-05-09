class Solution {
public:
	int titleToNumber(string s) {
		int count = 0;
		for (int i = s.size() - 1; i >= 0; --i)
		{
			int timess = s.size() - 1 - i == 0 ? 1 : (pow(26, (s.size() - 1 - i)));
			count += ((s[i] - 'A' + 1) *timess);
		}
		return count;
	}
};