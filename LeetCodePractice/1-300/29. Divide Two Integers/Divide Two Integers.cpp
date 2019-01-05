class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN && divisor == -1)
			return INT_MAX;
		int sign = (dividend < 0 ^ divisor < 0) ? -1 : 1;
		long long dvd = labs(dividend), dvs = labs(divisor);
		int result = 0;
		while (dvd >= dvs)
		{
			long long tmp = dvs, mul = 1;
			while (dvd >= (tmp << 1))
			{
				tmp <<= 1;
				mul <<= 1;
			}
			dvd -= tmp;
			result += mul;
		}
		return result * sign;
	}
};