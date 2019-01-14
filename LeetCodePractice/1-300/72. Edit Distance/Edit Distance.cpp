class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; ++i)//注意看懂
			dp[i][0] = i;
		for (int i = 1; i <= n; ++i)//注意看懂
			dp[0][i] = i;
		for (int i = 1; i <= m; ++i)//从1开始
		{
			for (int j = 1; j <= n; ++j)//从1开始
			{
				if (word1[i - 1] == word2[j - 1])//注意这里的word1[i - 1]和word2[j - 1],因为数组是从0开始的，要对应
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1), dp[i][j - 1] + 1);//求三个中的最小
			}
		}
		return dp[m][n];
	}
};