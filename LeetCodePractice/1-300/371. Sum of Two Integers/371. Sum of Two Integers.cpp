//¿´Í¼½âhttps://www.cnblogs.com/dyzhao-blog/p/5662891.html

class Solution {
public:
	int getSum(int a, int b) {
		/*
		int c = 0;
		while(b)
		{
		c = a^b;
		b = (a&b) << 1;
		a = c;
		}
		return a;
		*/
		a = *(unsigned int*)&a;
		b = *(unsigned int*)&b;
		return b == 0 ? a : getSum(a^b, (unsigned int)(a&b) << 1);
	}
};