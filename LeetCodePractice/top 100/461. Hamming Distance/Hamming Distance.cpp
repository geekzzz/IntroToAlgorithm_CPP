class Solution {
public:
	int hammingDistance(int x, int y) {
		int count = 0;
		int n = x ^ y;
		while (n)
		{
			count++;
			n = (n - 1)&n;//n & (n - 1) 的作用是吧最右边的一位1变为0
		}
		return count;
	}
};