class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<string> combine(n, std::string(n, '.'));
		backtrack(result, combine, 0, n);
		return result;
	}
	void backtrack(vector<vector<string>>& result, vector<string> & combine, int row, int n)
	{
		if (row == n)
		{
			result.push_back(combine);
			return;//×¢Òâreturn
		}

		for (int i = 0; i < n; ++i)
		{
			combine[row][i] = 'Q';
			if (isValid(combine, i, row, n))
				backtrack(result, combine, row + 1, n);
			combine[row][i] = '.';
		}
	}
	bool isValid(vector<string> combine, int col, int row, int n)
	{
		//check  col
		for (int i = 0; i < row; ++i)
			if (combine[i][col] == 'Q')
				return false;
		//check 45
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
			if (combine[i][j] == 'Q')
				return false;
		//check 135
		for (int i = row - 1, j = col + 1; i >= 0 && j >= 0; --i, ++j)
			if (combine[i][j] == 'Q')
				return false;
		return true;
	}
};