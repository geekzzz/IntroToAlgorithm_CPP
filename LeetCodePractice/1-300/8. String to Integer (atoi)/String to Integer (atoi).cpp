class Solution {
public:
	int myAtoi(string str) {
		bool sign = true;
		int i = 0;
		int result = 0;
		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
		{
			sign = false;
			i++;
		}
		else if (str[i] == '+')
			i++;
		while (str[i] >= '0' &&  str[i] <= '9' && i < str.size())
		{
			if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '7' > 0))
				return sign ? INT_MAX : INT_MIN;
			result = (result * 10) + (str[i] - '0');
			i++;
		}
		return sign ? result : -result;
	}
};