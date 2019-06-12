//
class Solution {
public:
	int arrangeCoins(int n) {
		int h = n;
		int l = 0;
		while (l <= h)
		{
			int m = l + (h - l) / 2;
			long long t = m*(m + 1l) / 2;//注意，这里一定要用1l,否则m*m + 1会被当成int运算溢出
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
//另一种写法
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