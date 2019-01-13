//一个简单的dp思路：只能往左走或者往下走，所以dp的方程即为： dp[i][j]  = dp[i - 1][j] + dp[i][j - 1]
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> v(m, vector<int>(n, 1));
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				v[i][j] = v[i - 1][j] + v[i][j - 1];
			}
		}
		return v[m - 1][n - 1];
	}
};