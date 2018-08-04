/*
注意 ，这道题值的范围为 [−2^31,  2^31 − 1].超出范围的返回0

int 能表示的数范围为 -2147483648～2147483647 ，其中有一个测试用例，1534236469 输入时在int 范围内，但是reverse以后大于int 能表示的范围。
*/

class Solution {
public:
	int reverse(int x) {
		long long ans = 0;
		while (x != 0)
		{
			ans = ans * 10 + x % 10;
			x /= 10;
		}
		return (ans < INT_MIN || ans > INT_MAX) ? 0 : ans;
	}
};