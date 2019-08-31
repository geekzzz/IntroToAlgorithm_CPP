//��ͼ��https://www.cnblogs.com/dyzhao-blog/p/5662891.html
//https://github.com/azl397985856/leetcode/blob/master/problems/371.sum-of-two-integers.md
//�����������ͬ��λ0����ͬ��λ1��������ǿ��԰���򿴳���һ�ֲ���λ�ļӼ�������������ȫ��λ1��λ1������λ0��������ǿ�������֮������һλ����ʾ��λ��
class Solution {
public:
	int getSum(int a, int b) {
		/*
		int c = 0;
		while(b)
		{
		c = a^b;
		b = (a&b) << 1;
		a = c;
		}
		return a;
		*/
		a = *(unsigned int*)&a;
		b = *(unsigned int*)&b;
		return b == 0 ? a : getSum(a^b, (unsigned int)(a&b) << 1);
	}
};