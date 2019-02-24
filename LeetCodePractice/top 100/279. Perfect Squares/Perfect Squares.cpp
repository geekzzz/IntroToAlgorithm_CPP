//dp˼�뿴����
class Solution {
public:
	int numSquares(int n) {
		if (n < 0)
			return 0;
		vector<int> dp(n + 1, INT_MAX);//ע������Ҫ��ʼ��ΪINT_MAX
		dp[0] = 0;//ע��dp[0]����ҪΪ0���������dp[1]ʱ����dp[0]�ͻ����
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j*j <= i; ++j)
			{
				dp[i] = min(dp[i], dp[i - j*j] + 1);
			}
		}
		return dp[n];
	}
};

