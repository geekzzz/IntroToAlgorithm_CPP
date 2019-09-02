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
			for (int k = m; k >= 0; --k) {    //�����ǴӴ�С

				if (k >= A[i - 1])
				{
					//ע������Ϊk��������k- 1,��ǰ�����Ӧ
					dp[k] = max(dp[k], dp[k - A[i - 1]] + V[i - 1]);//��lintcode 92 ��Ψһ��һ����������ı�һ��
				}

			}
		}
		return dp[m];
	}
};