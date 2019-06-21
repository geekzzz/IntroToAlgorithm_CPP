class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int maxres = 0;
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[0].size(); ++j)
			{
				if (grid[i][j] == 1)
				{
					maxres = max(dfs(grid, i, j), maxres);
				}

			}
		}
		return maxres;
	}
	int dfs(vector<vector<int>>& grid, int i, int j)
	{
		if (i < 0 || i > grid.size() - 1 || j < 0 || j > grid[0].size() - 1 || grid[i][j] == 0)
			return 0;
		//int res = grid[i][j];
		grid[i][j] = 0;
		int res = 1;
		res += dfs(grid, i - 1, j);
		res += dfs(grid, i + 1, j);
		res += dfs(grid, i, j - 1);
		res += dfs(grid, i, j + 1);
		return res;
	}
};
