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
		ע�����ﲻ������д��
		if (n > 0)
		{
		s += '(';
		addPar(v,s, n - 1, m + 1);
		}
		��Ϊ�����
		if (m > 0)
		{
		addPar(v, s + ')', n, m - 1);
		}
		�������õ����������ֱ�Ӹı���s���������᲻��ȷ

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