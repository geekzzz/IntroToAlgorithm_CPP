//n & (n - 1)����ʹ��ǰλ�����λ��ȫ����0������n = 1011000, n - 1 = 1010111,&�Ժ�������1010000��ֻҪû�б�Ϊ0����һ������һ��1�����Կ���ͳ��
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int result = 0;
		while (n)
		{
			n &= n - 1;
			result++;
		}
		return result;
	}
};