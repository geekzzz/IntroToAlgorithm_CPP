class Solution {
public:
	int hammingDistance(int x, int y) {
		int count = 0;
		int n = x ^ y;
		while (n)
		{
			count++;
			n = (n - 1)&n;//n & (n - 1) �������ǰ����ұߵ�һλ1��Ϊ0
		}
		return count;
	}
};