class Solution {
public:
	/**
	* @param m: An integer m denotes the size of a backpack
	* @param A: Given n items with size A[i]
	* @param V: Given n items with value V[i]
	* @return: The maximum value
	*/
	int backPackII(int m, vector<int> &A, vector<int> &V) {
		int n = A.size();
		vector<int> dp(m + 1, 0);

		for (int i = 1; i <= n; ++i) {
			for (int k = m; k >= 0; --k) {    //必须是从大到小

				if (k >= A[i - 1])
				{
					//注意这里为k，而不是k- 1,与前面相对应
					dp[k] = max(dp[k], dp[k - A[i - 1]] + V[i - 1]);//和lintcode 92 题唯一不一样的是这里改变一下
				}

			}
		}
		return dp[m];
	}
};