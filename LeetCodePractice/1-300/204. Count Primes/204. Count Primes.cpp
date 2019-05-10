//求素数的方法，筛法
class Solution {
public:
	int countPrimes(int n) {
		if (!n)
			return 0;
		vector<bool> prime(n, true);//这里只能分配n个，表示从0-n所对应的数字n是否为素数
		prime[0] = false;
		prime[1] = false;
		for (int i = 0; i < sqrt(n); ++i)
		{
			if (prime[i])
			{
				for (int j = i * i; j < n; j += i)
				{
					prime[j] = false;
				}
			}
		}
		return count(prime.begin(), prime.end(), true);
	}

};