//和leetcode 10 思想很像，比正则简单

class Solution {
public:

	bool isMatch(string s, string p) {
		int m = s.size();
		int n = p.size();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= n; ++i)//注意这里的处理和正则不一样
		{
			if (p[i - 1] == '*')
				dp[0][i] = dp[0][i - 1];
		}

		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (p[j - 1] == '*')
				{
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];//注意这里和正则处理不一样
				}
				else
				{
					dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
				}
			}
		}
		return dp[m][n];
	}
};