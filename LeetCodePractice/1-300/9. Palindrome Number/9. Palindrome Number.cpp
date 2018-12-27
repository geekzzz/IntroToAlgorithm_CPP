//我的解法：直接把int翻转，然后比较
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

//推荐解法：只翻转一半，然后比较翻转一半的数与前一半是否一样（长度为偶数时，如1221，则x = 12，sum = 12）或者除以10是否一样（长度为奇数，如12321，则x = 12，sum = 123，则x == sum/ 10）
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