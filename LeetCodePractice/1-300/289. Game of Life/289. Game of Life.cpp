class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int m = board.size();
		if (!m)
			return;
		int n = board[0].size();
		if (!n)
			return;
		vector<vector<int>> board1(board);
		int count = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				count = counter(i, j, board1);
				if (count == 0 || count == 1)
					board[i][j] = 0;
				else if (count == 2 || count == 3)
				{
					if (count == 3 && board1[i][j] == 0)
						board[i][j] = 1;
					else
						board[i][j] = board[i][j];
				}
				else
				{
					board[i][j] = 0;
				}
			}
		}
	}
	int counter(int i, int j, vector<vector<int>>& board)
	{
		int count = 0;
		int m = board.size();
		int n = board[0].size();
		if (i > 0 && j > 0)
			count += board[i - 1][j - 1];
		if (i > 0)
			count += board[i - 1][j];
		if (i > 0 && j < n - 1)
			count += board[i - 1][j + 1];
		if (i < m - 1)
			count += board[i + 1][j];
		if (i < m - 1 && j > 0)
			count += board[i + 1][j - 1];
		if (i < m - 1 && j < n - 1)
			count += board[i + 1][j + 1];
		if (j > 0)
			count += board[i][j - 1];
		if (j < n - 1)
			count += board[i][j + 1];
		return count;
	}
};