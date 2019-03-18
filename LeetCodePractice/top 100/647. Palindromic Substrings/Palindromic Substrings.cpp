//思想和lc516类似
class Solution {
public:
	int countSubstrings(string s) {
		int n = s.size();
		int count = 0;

		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = i; j < n; ++j)
			{
				dp[i][j] = (s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1]));//注意这里！！！ 判断j-i < 3是解决例如AXA这种回文情况，或者AA,A这三种情况，其他的则用dp[i + 1][j  -1]判断
				if (dp[i][j])
					count++;
			}
		}
		return count;
	}
};