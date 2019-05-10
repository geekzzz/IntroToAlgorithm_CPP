//n & (n - 1)可以使当前位后面的位数全部置0，例如n = 1011000, n - 1 = 1010111,&以后则变成了1010000，只要没有变为0，则一定存在一个1，所以可以统计
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int result = 0;
		while (n)
		{
			n &= n - 1;
			result++;
		}
		return result;
	}
};