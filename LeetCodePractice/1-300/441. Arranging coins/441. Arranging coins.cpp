//
class Solution {
public:
	int arrangeCoins(int n) {
		int h = n;
		int l = 0;
		while (l <= h)
		{
			int m = l + (h - l) / 2;
			long long t = m*(m + 1l) / 2;//ע�⣬����һ��Ҫ��1l,����m*m + 1�ᱻ����int�������
			if (t > n)
				h = m - 1;
			else if (t < n)
				l = m + 1;
			else
				return m;
		}
		return h;
	}
};
//��һ��д��
class Solution {
public:
	int arrangeCoins(int n) {
		int h = n;
		int l = 0;
		while (l <= h)
		{
			int m = l + (h - l) / 2;
			long long t = m*(m + 1l) / 2;
			if (t > n)
				h = m - 1;
			else
				l = m + 1;
		}
		return l - 1;



	}
};