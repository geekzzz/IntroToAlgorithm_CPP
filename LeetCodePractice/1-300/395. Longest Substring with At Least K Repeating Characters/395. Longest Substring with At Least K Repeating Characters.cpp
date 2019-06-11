
//基于递归的解法1，效率不高
int helper(string s, int k)
{
	vector<int> c(26, 0);
	for (int i = 0; i < s.size(); ++i)
		c[s[i] - 'a']++;
	int i = 0;
	for (; i < s.size(); ++i)
	{
		if (c[s[i] - 'a'] < k)
		{
			return max(
				helper(s.substr(0, i), k),
				helper(s.substr(i + 1), k)
			);
		}
	}
	return s.size();

}
int longestSubstring(string s, int k) {
	return helper(s, k);
}
//基于递归的解法2，效率不高
int helper(int start, int end, string s, int k)
{
	vector<int> c(26, 0);
	/*if (start > end || end - start < k)
		return 0;*/
	for (int i = start; i <= end; ++i)
		c[s[i] - 'a']++;
	for (int i = start; i <= end; ++i)
	{
		if (c[s[i] - 'a'] < k)
		{
			return max(helper(start, i - 1, s, k), helper(i + 1, end, s, k));
		}
	}
	return end - start + 1;
}
int longestSubstring(string s, int k) {
	return helper(0, s.size() - 1, s, k);
}


//这种写法效率高一点
class Solution {
public:
	int longestSubstring(string s, int k) {
		vector<int> c(26, 0);
		for (int i = 0; i < s.size(); ++i)
			c[s[i] - 'a']++;
		int len = 0;
		int maxlen = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (c[s[i] - 'a'] >= k)
				len++;
			else if (len > 0)
			{
				maxlen = max(maxlen, longestSubstring(s.substr(i - len, len), k));
			}
		}
		if (len == s.size())
			return len;
		if (len > 0)
		{
			maxlen = max(maxlen, longestSubstring(s.substr(s.size() - len, len), k));
		}
		return maxlen;
	}

};