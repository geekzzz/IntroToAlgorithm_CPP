//dp思想看代码
class Solution {
public:
	int numSquares(int n) {
		if (n < 0)
			return 0;
		vector<int> dp(n + 1, INT_MAX);//注意这里要初始化为INT_MAX
		dp[0] = 0;//注意dp[0]必须要为0，否则计算dp[1]时依赖dp[0]就会出错
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

