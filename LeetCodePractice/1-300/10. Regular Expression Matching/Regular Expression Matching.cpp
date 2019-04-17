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

		//ֻ�е�p����Ϊa*b*a*a*������ʽʱ��������������
		/*
		p = c * a * b
		when first * is 0, p = a * b
		when second * is 2, p = aab.
		'*' Matches zero or more of the preceding element of the pattern string. This means 'c' can be repeated 0 or more times. ����a*b������Ա��Ϊa�����ظ�0�Σ������ظ�n�Σ������ת��Ϊb����ab,aab,aaab,aaaab......
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
					f[i][j] = f[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && f[i - 1][j]);//��һ�������f[i][j-2]Ϊtrue����*ֱ��ƥ���ʾǰ���ַ�����0�Σ������������ڶ��������s[i - 1]==p[j - 2]��ʾp��*��ǰһ���ַ���s�ĵ�ǰ�ַ���ȣ�p[j-2] == '.'Ҳ��ʾ��s[i - 1]ƥ��
				}
			}
		}
		return f[m][n];

	}
};