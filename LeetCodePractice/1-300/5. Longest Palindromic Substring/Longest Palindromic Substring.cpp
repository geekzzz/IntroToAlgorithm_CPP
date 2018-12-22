class Solution {
public:
	string longestPalindrome(string s) {
		int start = 0, maxlen = 1;
		for (int i = 0; i< s.size();)
		{
			if (s.size() - i < maxlen / 2) break;

			int k = i, j = i;
			while (k < s.size() - 1 && s[k] == s[k + 1])
				++k;
			i = k + 1;
			while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1])
			{
				++k;
				--j;
			}
			if (k - j + 1 > maxlen)
			{
				maxlen = k - j + 1;
				start = j;
			}
		}
		return s.substr(start, maxlen);
	}
};