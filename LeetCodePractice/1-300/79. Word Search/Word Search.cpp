class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size(), n = board[0].size();
		vector<vector<bool>> visit(m, vector<bool>(n, false));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (ex(board, visit, word, i, j, 0))
					return true;
			}
		}
		return false;
	}
	bool ex(vector<vector<char>>& board, vector<vector<bool>>& visit, string word, int x, int y, int wordindex)
	{
		if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || word[wordindex] != board[x][y] || visit[x][y] == true)//注意这里判别的先后，如果先判断 word[wordindex] != board[x][y]而不是x < 0 || y < 0 || x >= board.size() || y >= board[0].size()会出现越界
			return false;
		if (wordindex == word.size() - 1)
			return true;
		visit[x][y] = true;
		bool isfind = (
			ex(board, visit, word, x + 1, y, wordindex + 1) ||
			ex(board, visit, word, x - 1, y, wordindex + 1) ||
			ex(board, visit, word, x, y + 1, wordindex + 1) ||
			ex(board, visit, word, x, y - 1, wordindex + 1)
			);
		visit[x][y] = false;
		return isfind;
	}
};