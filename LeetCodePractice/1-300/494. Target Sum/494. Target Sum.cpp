//最简单的backtrack，暴力
class Solution {
public:
	int result = 0;
	int findTargetSumWays(vector<int>& nums, int S) {
		backtrack(nums, 0, S, 0);
		return result;
	}
	void backtrack(vector<int>& nums, int start, int S, int sum)
	{
		if (start == nums.size())
		{
			if (sum == S)
				result++;
			return;
		}
		backtrack(nums, start + 1, S, sum + nums[start]);
		backtrack(nums, start + 1, S, sum - nums[start]);
	}
};
/*
https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C%2B%2B-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation
//dp 解法 ，转化为The original problem statement is equivalent to:
Find a subset of nums that need to be positive, and the rest of them negative, such that the sum is equal to target

Let P be the positive subset and N be the negative subset
For example :
Given nums = [1, 2, 3, 4, 5] and target = 3 then one possible solution is + 1 - 2 + 3 - 4 + 5 = 3
Here positive subset is P = [1, 3, 5] and negative subset is N = [2, 4]

Then let's see how this can be converted to a subset sum problem:

sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
2 * sum(P) = target + sum(nums)
So the original problem has been converted to a subset sum problem as follows :
Find a subset P of nums such that sum(P) = (target + sum(nums)) / 2

Note that the above formula has proved that target + sum(nums) must be even

然后就可以转化为和 LC 416. Partition Equal Subset Sum 问题类似的问题
*/

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int n = nums.size();
		int sum = 0;
		for (auto x : nums)
			sum += x;
		if (sum < S)
			return 0;
		sum += S;
		if (sum % 2 > 0)
			return 0;
		sum /= 2;
		vector<int> dp(sum + 1, 0);//注意01背包问题可以优化为1维的情况
		dp[0] = 1;

		for (int i = 0; i < n; ++i)
		{
			for (int j = sum; j >= nums[i]; --j)//注意优化以后这里是从后往前扫描
			{
				dp[j] = dp[j] + dp[j - nums[i]];
			}
		}
		return dp[sum];
	}
};


int findTargetSumWays(vector<int>& nums, int S) {
	int n = nums.size();
	int sum = 0;
	for (auto x : nums)
		sum += x;
	int res;
	if (sum < S)
		return 0;
	sum = sum + S;
	if (sum % 2)
		return 0;
	sum /= 2;
	res = targetsum(nums,sum );
	return sum;
}
int targetsum(vector<int>& nums, int sum)
{
	// sort(nums.begin(),nums.end());
	// reverse(nums.begin(),nums.end());
	vector<int> dp(sum + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = sum; j >= nums[i]; --j)
		{
			dp[j] = dp[j] + dp[j - nums[i]];
		}
	}
	return dp[sum];
}
