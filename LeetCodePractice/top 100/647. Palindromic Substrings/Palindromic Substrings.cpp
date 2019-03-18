//˼���lc516����
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
				dp[i][j] = (s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1]));//ע��������� �ж�j-i < 3�ǽ������AXA���ֻ������������AA,A���������������������dp[i + 1][j  -1]�ж�
				if (dp[i][j])
					count++;
			}
		}
		return count;
	}
};