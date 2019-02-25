//dp�ⷨ��N^2���Ӷ�
//dp[i]������dp[i]Ϊ������ǰ��ĵ������ĳ���
//������Ƶ  https://www.youtube.com/watch?v=fV-TF4OvZpk
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		int maxL = 1;//maxL��iָ��ÿ���ƶ��Ƚϼ�¼һ��
		vector<int> dp(n + 1, 1);//��ʼ��Ϊ1��������DP[I]Ϊ��β��
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] > nums[j])
				{
					dp[i] = max(dp[j] + 1, dp[i]);
				}
			}
			maxL = max(maxL, dp[i]);

		}
		return maxL;
	}
};

//nlogn�ⷨ��