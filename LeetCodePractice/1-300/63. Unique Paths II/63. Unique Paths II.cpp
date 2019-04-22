class Solution {
public:

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		if (!m)
			return 0;
		int n = obstacleGrid[0].size();
		vector<vector<unsigned int>> dp(m + 1, vector<unsigned int>(n + 1, 0));
		for (int i = 0; i < m; ++i)
		{
			if (obstacleGrid[i][0] != 1)
				dp[i][0] = 1;
			else
				break;
		}

		for (int i = 0; i < n; ++i)
		{
			if (obstacleGrid[0][i] != 1)
				dp[0][i] = 1;
			else
				break;
		}

		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (obstacleGrid[i][j] != 1)
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				else
					continue;
			}
		}
		return dp[m - 1][n - 1];
	}

};