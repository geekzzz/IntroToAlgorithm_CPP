
//dp维护最大边长，因为是正方形，所以边长方程为：dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (!m)
			return 0;
		int n = matrix[0].size();
		int maxEdge = 0;
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (!i || !j || matrix[i][j] == '0')
					dp[i][j] = matrix[i][j] == '0' ? 0 : 1;
				else
				{
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;

				}
				if (dp[i][j] > maxEdge)
					maxEdge = dp[i][j];
			}
		}
		return maxEdge * maxEdge;
	}
};