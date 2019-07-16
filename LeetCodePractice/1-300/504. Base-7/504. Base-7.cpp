class Solution
{
public:
	string convertToBase7(int num)
	{
		string res;
		if (!num)
		{
			string r("0");
			return r;
		}
		int n = abs(num);
		while (n)
		{
			res = to_string(n % 7) + res;
			n /= 7;
		}
		if (num >= 0)
			return res;
		else
			return "-" + res;
	}
};