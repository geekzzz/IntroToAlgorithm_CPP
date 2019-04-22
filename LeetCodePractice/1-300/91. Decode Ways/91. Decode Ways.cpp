class Solution {
public:
	int numDecodings(string s) {
		int n = s.size();
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = s[0] == '0' ? 0 : 1;
		for (int i = 2; i <= n; ++i)
		{
			int first = stoi(s.substr(i - 1, 1));
			int second = stoi(s.substr(i - 2, 2));
			if (first != 0)
				dp[i] += dp[i - 1];
			if (second >= 10 && second <= 26)
				dp[i] += dp[i - 2];
		}
		return dp[n];
	}

};