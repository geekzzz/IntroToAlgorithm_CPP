//ע�����Ƶ����⣬�磺��ʹ�õ�������������a��b ��  a = a^b; b = a^b;a = a^b;
//�Լ�count bit���� 191. Number of 1 Bits


class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t result = 0;
		for (int i = 0; i < 32; ++i)
		{
			result = result << 1;
			result += n & 1;
			n = n >> 1;
		}
		return result;
	}
};