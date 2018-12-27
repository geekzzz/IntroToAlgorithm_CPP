//�ҵĽⷨ��ֱ�Ӱ�int��ת��Ȼ��Ƚ�
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x != 0 && x % 10 == 0))
			return false;
		int xx = x;
		int reverse = 0;
		while (x != 0)
		{
			reverse = reverse * 10 + (x % 10);
			x = x / 10;
		}
		return reverse == xx;
	}
};

//�Ƽ��ⷨ��ֻ��תһ�룬Ȼ��ȽϷ�תһ�������ǰһ���Ƿ�һ��������Ϊż��ʱ����1221����x = 12��sum = 12�����߳���10�Ƿ�һ��������Ϊ��������12321����x = 12��sum = 123����x == sum/ 10��
class Solution {
public:
	bool isPalindrome(int x) {
		if (x<0 || (x != 0 && x % 10 == 0)) return false;
		int sum = 0;
		while (x>sum)
		{
			sum = sum * 10 + x % 10;
			x = x / 10;
		}
		return (x == sum) || (x == sum / 10);
	}
};