class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1)//否则会出现除以0的情况
			return x;
		int l = 1;//初始化为1，否则会出现除0的情况
		int h = x;
		int mid;
		while (l <= h)
		{
			mid = l + (h - l) / 2;
			if (mid < x / mid)//用x/mid来判断，如果用mid*mid来判断不对
			{
				h = mid - 1;
			}
			else if (mid > x / mid)
			{
				l = mid + 1;
			}
			else
				return mid;

		}
		return h;
	}
};
