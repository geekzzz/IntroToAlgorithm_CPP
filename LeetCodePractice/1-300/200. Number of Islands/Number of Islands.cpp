//DFS搜索
//做法与lc 79 word search 类似
class Solution {
public:
	int m;
	int n;
	int numIslands(vector<vector<char>>& grid) {
		m = grid.size();
		if (m == 0)
			return 0;
		n = grid[0].size();
		int result = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (grid[i][j] == '1')
				{
					++result;
					DFS(i, j, grid);
				}
			}
		}
		return result;
	}
	void DFS(int i, int j, vector<vector<char>>& grid)
	{
		if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1')
			return;
		grid[i][j] = '0';
		DFS(i - 1, j, grid);
		DFS(i + 1, j, grid);
		DFS(i, j + 1, grid);
		DFS(i, j - 1, grid);
	}
};