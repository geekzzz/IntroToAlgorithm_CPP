class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool ans = true;
		set<char> row;
		set<char> col;
		set<char> block;
		for (int i = 0; i < 9; ++i)
		{
			row.clear();
			col.clear();
			for (int j = 0; j < 9; ++j)
			{
				//¼ì²ârow
				if (board[i][j] != '.')
				{
					if (row.find(board[i][j]) != row.end())
					{
						return false;
					}
					row.insert(board[i][j]);
				}
				//¼ì²âcol£¬×¢Òâi,jµßµ¹
				if (board[j][i] != '.')
				{
					if (col.find(board[j][i]) != col.end())
					{
						return false;
					}
					col.insert(board[j][i]);
				}
				//¼ì²âblock
				if (i % 3 == 0 && j % 3 == 0)
				{
					block.clear();
					for (int m = 0; m < 3; ++m)
					{
						for (int n = 0; n < 3; ++n)
						{
							if (board[i + m][j + n] != '.')
							{
								if (block.find(board[i + m][j + n]) != block.end())
								{
									return false;
								}
								block.insert(board[i + m][j + n]);
							}
						}
					}
				}
			}
		}
		return ans;
	}
};