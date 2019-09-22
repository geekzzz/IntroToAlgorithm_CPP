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


// greedy solution with idea of DFS
// starj stores the position of last * in p
// last_match stores the position of the previous matched char in s after a *
// e.g. 
// s: a c d s c d
// p: * c d
// after the first match of the *, starj = 0 and last_match = 1
// when we come to i = 3 and j = 3, we know that the previous match of * is actually wrong, 
// (the first branch of DFS we take is wrong)
// then it resets j = starj + 1 
// since we already know i = last_match will give us the wrong answer
// so this time i = last_match+1 and we try to find a longer match of *
// then after another match we have starj = 0 and last_match = 4, which is the right solution
// since we don't know where the right match for * ends, we need to take a guess (one branch in DFS), 
// and store the information(starj and last_match) so we can always backup to the last correct place and take another guess.

bool isMatch(string s, string p) {
	int i = 0, j = 0;
	int m = s.length(), n = p.length();
	int last_match = -1, starj = -1;
	while (i < m) {
		if (j < n && (s[i] == p[j] || p[j] == '?')) {
			i++; j++;
		}
		else if (j < n && p[j] == '*') {
			starj = j;
			j++;
			last_match = i;
		}
		else if (starj != -1) {
			j = starj + 1;
			last_match++;
			i = last_match;
		}
		else return false;
	}
	while (p[j] == '*' && j <n) j++;
	return j == n;
}