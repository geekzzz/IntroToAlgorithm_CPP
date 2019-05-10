//floyed cycle detection algorithm,���Ƶ���Ŀ�����ж������л�����Ŀ��ʹ�ÿ���ָ���˼��
class Solution {
public:
	bool isHappy(int n) {
		int slow = n, fast = n;
		do {
			slow = helper(slow);
			fast = helper(fast);
			fast = helper(fast);
		} while (slow != fast);

		return slow == 1;
	}
	int helper(int n)
	{
		int tmp = 0;
		while (n)
		{
			tmp += (n % 10)*(n % 10);
			n /= 10;
		}
		return tmp;
	}
};

//�ⷨ1����set����¼֮ǰ�����֣��Ƚ��˷ѿռ�
class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> s;
		while (n != 1)
		{
			int tmp = 0;
			while (n)
			{
				tmp += (n % 10)*(n % 10);
				n /= 10;
			}

			if (s.find(tmp) != s.end())
				break;
			n = tmp;
			s.insert(n);
		}
		return n == 1;

	}
};
//�ⷨ2����΢�Ľ���һ�㣬�����ҹ��ɷ��֣�n = 4�������Զ������happy number ���԰������������ȥ
class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> s;
		while (n != 1 && n != 4)
		{
			int tmp = 0;
			while (n)
			{
				tmp += (n % 10)*(n % 10);
				n /= 10;
			}

			if (s.find(tmp) != s.end())
				break;
			n = tmp;
			s.insert(n);
		}
		return n == 1;

	}
};
