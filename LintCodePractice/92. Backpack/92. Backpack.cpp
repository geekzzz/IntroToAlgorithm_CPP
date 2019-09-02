//�ⷨ1����ά���飬�ռ�δ�Ż�
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
					//ע��ת�Ʒ�����dp[i][j] =  max(dp[i - 1][j],dp[i - 1][j - nums[i - 1]] + nums[i - 1]),�����涼��i - 1,�ռ��Ż�����Ϊi����
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
				}
					
			}
		}
		return dp[n][m];
	}
};
//�ռ��Ż���
class Solution {
public:
	int backPack(int m, vector<int> &nums) {
		int n = nums.size();
		vector<int> dp(m + 1, 0);

		for (int i = 1; i <= n; ++i) {
			for (int k = m; k >= 0; --k) {    //�����ǴӴ�С

				if (k >= nums[i - 1])
				{
					//ע������Ϊk��������k- 1,��ǰ�����Ӧ
					dp[k] = max(dp[k], dp[k - nums[i - 1]] + nums[i - 1]);
				}
					
			}
		}
		return dp[m];
	}
};