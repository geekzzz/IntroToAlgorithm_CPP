//看图解https://www.cnblogs.com/dyzhao-blog/p/5662891.html
//https://github.com/azl397985856/leetcode/blob/master/problems/371.sum-of-two-integers.md
//由于异或是相同则位0，不同则位1，因此我们可以把异或看成是一种不进位的加减法。由于与是全部位1则位1，否则位0，因此我们可以求与之后左移一位来表示进位。
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