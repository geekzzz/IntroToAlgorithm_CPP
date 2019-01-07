class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> v;
		if (n == 0)
			return v;
		addPar(v, "", n, 0);
		return v;
	}
	void addPar(vector<string> &v, string s, int n, int m)
	{
		if (n == 0 && m == 0)
		{
			v.push_back(s);
			return;
		}
		/*
		注意这里不能这样写：
		if (n > 0)
		{
		s += '(';
		addPar(v,s, n - 1, m + 1);
		}
		因为后面的
		if (m > 0)
		{
		addPar(v, s + ')', n, m - 1);
		}
		还会再用到，所以如果直接改变了s，后面结果会不正确

		*/

		if (n > 0)
		{
			addPar(v, s + '(', n - 1, m + 1);
		}
		if (m > 0)
		{
			addPar(v, s + ')', n, m - 1);
		}
	}
};