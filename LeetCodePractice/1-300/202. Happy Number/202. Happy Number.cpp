//floyed cycle detection algorithm,类似的题目还有判断链表有环的题目，使用快慢指针的思想
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

//解法1，用set来记录之前的数字，比较浪费空间
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
//解法2，稍微改进了一点，根据找规律发现，n = 4的情况永远不能是happy number 所以把这个情况加入进去
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
