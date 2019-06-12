class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1)//�������ֳ���0�����
			return x;
		int l = 1;//��ʼ��Ϊ1���������ֳ�0�����
		int h = x;
		int mid;
		while (l <= h)
		{
			mid = l + (h - l) / 2;
			if (mid < x / mid)//��x/mid���жϣ������mid*mid���жϲ���
			{
				h = mid - 1;
			}
			else if (mid > x / mid)
			{
				l = mid + 1;
			}
			else
				return mid;

		}
		return h;
	}
};
