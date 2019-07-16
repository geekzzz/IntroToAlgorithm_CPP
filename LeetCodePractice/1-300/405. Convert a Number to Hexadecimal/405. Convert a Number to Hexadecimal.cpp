class Solution {
public:
	string toHex(int num) {
		if (!num)
			return string("0");
		string res;
		vector<char> m{ '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
		while (num)
		{
			res = m[num & 0xf] + res;
			num = (unsigned int)num >> 4;
		}
		return res;
	}
};