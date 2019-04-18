
//解法1，暴力
class Solution {
public:
	int result = 0;
	int totalNQueens(int n) {
		vector<string> combine(n, std::string(n, '.'));
		backtrack(combine, 0, n);
		return result;
	}
	void backtrack(vector<string> & combine, int row, int n)
	{
		if (row == n)
		{
			result++;
			return;
		}

		for (int i = 0; i < n; ++i)
		{
			combine[row][i] = 'Q';
			if (isValid(combine, i, row, n))
				backtrack(combine, row + 1, n);
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

// 解法2，用三个数组表示列，45度，135度方向有没有Q
class Solution {
public:
	int result = 0;
	int totalNQueens(int n) {
		unordered_set<int> scol;
		unordered_set<int> occupy45;
		unordered_set<int> occupy135;
		backtrack(scol, occupy45, occupy135, 0, n);
		return result;
	}
	void backtrack(unordered_set<int> & scol, unordered_set<int> & occupy45, unordered_set<int> & occupy135, int row, int n)
	{
		for (int col = 0; col < n; ++col)
		{
			if (scol.find(col) != scol.end())
				continue;
			int id1 = col + row;//注意这里，表示45度方向重复
			int id2 = n - 1 + row - col;//注意这里，表示135度方向重复
			if (occupy45.find(id1) != occupy45.end())
				continue;
			if (occupy135.find(id2) != occupy135.end())
				continue;
			if (row == n - 1)
				result++;
			scol.insert(col);
			occupy45.insert(id1);
			occupy135.insert(id2);
			backtrack(scol, occupy45, occupy135, row + 1, n);
			scol.erase(scol.find(col));
			occupy45.erase(occupy45.find(id1));
			occupy135.erase(occupy135.find(id2));
		}
	}
};