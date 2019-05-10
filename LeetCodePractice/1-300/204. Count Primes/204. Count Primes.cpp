//�������ķ�����ɸ��
class Solution {
public:
	int countPrimes(int n) {
		if (!n)
			return 0;
		vector<bool> prime(n, true);//����ֻ�ܷ���n������ʾ��0-n����Ӧ������n�Ƿ�Ϊ����
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