//相似题目还有power of three，power of four

class Solution {
public:
	bool isPowerOfTwo(int n) {
		return (n > 0) && !(n & (n - 1));//2的n次方分别为2^0 = 1,2^1 = 2,2^2 = 4......，二进制表示时，只能有一位有1，其他位必须为0，使用n&(n - 1)可以消除一个数最后一位的1，而2的n次方的数必然只有一位为1，其他都为0
	}
};