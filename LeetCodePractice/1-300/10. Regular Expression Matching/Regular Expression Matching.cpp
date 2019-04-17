class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size();
		int n = p.size();
		vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
		f[0][0] = true;
		for (int i = 1; i <= m; ++i)
		{
			f[i][0] = false;
		}

		//只有当p满足为a*b*a*a*这种形式时，才能满足条件
		/*
		p = c * a * b
		when first * is 0, p = a * b
		when second * is 2, p = aab.
		'*' Matches zero or more of the preceding element of the pattern string. This means 'c' can be repeated 0 or more times. 例如a*b，则可以表达为a可以重复0次，或者重复n次，则可以转化为b或者ab,aab,aaab,aaaab......
		*/
		for (int j = 1; j <= n; ++j)
		{
			f[0][j] = ('*' == p[j - 1] && f[0][j - 2]);
		}
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (p[j - 1] != '*')
				{
					f[i][j] = f[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.');
				}
				else
				{
					f[i][j] = f[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && f[i - 1][j]);//第一个情况，f[i][j-2]为true，则*直接匹配表示前面字符出现0次，满足条件；第二种情况，s[i - 1]==p[j - 2]表示p的*的前一个字符和s的当前字符相等，p[j-2] == '.'也表示和s[i - 1]匹配
				}
			}
		}
		return f[m][n];

	}
};