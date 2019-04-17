class Solution {
//背一下
public:
	string multiply(string num1, string num2) {
		int n1 = num1.size();
		int n2 = num2.size();
		string sum(n1 + n2, '0');//注意位数只能是n1 + n2

		for (int i = n1 - 1; i >= 0; --i)
		{
			int c = 0;//进位在这
			for (int j = n2 - 1; j >= 0; --j)
			{
				int tmp = (sum[i + j + 1] - '0') + ((num1[i] - '0') * (num2[j] - '0')) + c;//注意这句((num1[i] - '0') * (num2[j] - '0'))
				sum[i + j + 1] = tmp % 10 + '0';
				c = tmp / 10;
			}
			sum[i] += c;
		}

		size_t startpos = sum.find_first_not_of("0");
		if (string::npos != startpos) {
			return sum.substr(startpos);
		}
		return "0";
	}
};