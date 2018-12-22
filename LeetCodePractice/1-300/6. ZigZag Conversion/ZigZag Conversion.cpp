class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		string zigzag[numRows];
		int rows = 0;
		int step = 1;
		for (int i = 0; i < s.size(); ++i)
		{
			zigzag[rows].push_back(s[i]);
			if (rows == 0)
				step = 1;
			else if (rows == numRows - 1)
				step = -1;
			rows += step;
		}
		string result;
		for (int i = 0; i < numRows; ++i)
		{
			result += zigzag[i];
		}
		return result;
	}
};