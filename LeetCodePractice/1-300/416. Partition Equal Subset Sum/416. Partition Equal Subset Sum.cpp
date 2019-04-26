//01�������⣬ע��ռ��Ż��������û���Ż��İ汾���Ƕ�ά��
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int n = nums.size();
		int sum = 0;
		for (int i = 0; i < n; ++i)
			sum += nums[i];
		if (sum % 2)
			return false;
		sum /= 2;
		vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
		for (int i = 0; i < n + 1; ++i)
			dp[i][0] = true;
		for (int i = 1; i < sum + 1; ++i)
			dp[0][i] = false;
		for (int i = 1; i < n + 1; ++i)
		{
			for (int j = 1; j < sum + 1; ++j)
			{
				dp[i][j] = dp[i - 1][j];
				if (j >= nums[i - 1])
					dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
			}
		}
		return dp[n][sum];
	}
};
//�Ż���İ汾��һ��Ҫע�⿴
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int n = nums.size();
		int sum = 0;
		for (int i = 0; i < n; ++i)
			sum += nums[i];
		if (sum % 2)
			return false;
		sum /= 2;
		vector<bool> dp(sum + 1, false);
		dp[0] = true;
		for (int i = 0; i < n; ++i)
		{
			for (int j = sum; j >= 1; --j)
			{
				if (j >= nums[i])
					dp[j] = dp[j] || dp[j - nums[i]];
			}

		}
		return dp[sum];
	}
};