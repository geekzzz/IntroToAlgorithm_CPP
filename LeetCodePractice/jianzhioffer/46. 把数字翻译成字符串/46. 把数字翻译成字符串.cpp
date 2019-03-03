int numDecodings(string s)
{
	int n = s.size();
	if (n == 0)
		return 0;

	vector<int> dp(n + 1, 0);
	dp[n] = 1;
	for (int i = n - 1; i >= 0; --i)
	{
		if (s[i] == '0')
			dp[i] = 0;
		else
		{
			dp[i] = dp[i + 1];
			if (i < n - 1 && stoi(s.substr(i, 2)) <= 26)
				dp[i] += dp[i + 2];
		}
	}
	return dp[0];
}