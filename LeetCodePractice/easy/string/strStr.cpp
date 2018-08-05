/*
我自己的解法，brute-force algorithm
*/

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.length() == 0)
		{
			return 0;
		}
		if (needle.length() > haystack.length())
		{
			return -1;
		}
		for (int i = 0; i < haystack.length() - needle.length() + 1; ++i)
		{
			if (haystack[i] == needle[0])
			{
				for (int j = 0; j < needle.length(); ++j)
				{
					if (haystack[i + j] != needle[j])
					{
						break;
					}
					else
					{
						if (j == needle.length() - 1)
						{
							return i;
						}
					}
				}
			}
		}
		return -1;
	}
};

/*
别人的解法，非kmp，brute-force algorithm
*/

class Solution {
public:
	int strStr(string haystack, string needle) {
		int m = haystack.length(), n = needle.length();
		if (!n) {
			return 0;
		}
		for (int i = 0; i < m - n + 1; i++) {
			int j = 0;
			for (; j < n; j++) {
				if (haystack[i + j] != needle[j]) {
					break;
				}
			}
			if (j == n) {
				return i;
			}
		}
		return -1;
	}
};

/*
别人的解法，kmp
*/
class Solution {
public:
	int strStr(string haystack, string needle) {
		int m = haystack.length(), n = needle.length();
		if (!n) {
			return 0;
		}
		vector<int> lps = kmpProcess(needle);
		for (int i = 0, j = 0; i < m; ) {
			if (haystack[i] == needle[j]) {
				i++;
				j++;
			}
			if (j == n) {
				return i - j;
			}
			if ((i < m) && (haystack[i] != needle[j])) {
				if (j) {
					j = lps[j - 1];
				}
				else {
					i++;
				}
			}
		}
		return -1;
	}
private:
	vector<int> kmpProcess(string& needle) {
		int n = needle.length();
		vector<int> lps(n, 0);
		for (int i = 1, len = 0; i < n; ) {
			if (needle[i] == needle[len]) {
				lps[i++] = ++len;
			}
			else if (len) {
				len = lps[len - 1];
			}
			else {
				lps[i++] = 0;
			}
		}
		return lps;
	}
};