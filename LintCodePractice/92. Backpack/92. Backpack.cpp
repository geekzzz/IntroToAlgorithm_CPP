//解法1，二维数组，空间未优化
class Solution {
public:

	int backPack(int m, vector<int> &nums) {
		int n = nums.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = m; j >= 0; --j)
			{

				dp[i][j] = dp[i - 1][j];
				if (j >= nums[i - 1])
				{
					//注意转移方程是dp[i][j] =  max(dp[i - 1][j],dp[i - 1][j - nums[i - 1]] + nums[i - 1]),这里面都是i - 1,空间优化后，则为i！！
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
				}
					
			}
		}
		return dp[n][m];
	}
};
//空间优化后
class Solution {
public:
	int backPack(int m, vector<int> &nums) {
		int n = nums.size();
		vector<int> dp(m + 1, 0);

		for (int i = 1; i <= n; ++i) {
			for (int k = m; k >= 0; --k) {    //必须是从大到小

				if (k >= nums[i - 1])
				{
					//注意这里为k，而不是k- 1,与前面相对应
					dp[k] = max(dp[k], dp[k - nums[i - 1]] + nums[i - 1]);
				}
					
			}
		}
		return dp[m];
	}
};