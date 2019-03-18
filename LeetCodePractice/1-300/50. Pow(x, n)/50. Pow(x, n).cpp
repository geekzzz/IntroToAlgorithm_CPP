class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1;
		long long p = n;//�������������ΪINT_MINʱ��n = -n �����������long long�ȴ���int
		if (n < 0)
		{
			x = 1 / x;
			p = -p;
		}
		if (p % 2 == 0)
			return myPow(x*x, p / 2);
		else
			return x * myPow(x*x, p / 2);
	}
};