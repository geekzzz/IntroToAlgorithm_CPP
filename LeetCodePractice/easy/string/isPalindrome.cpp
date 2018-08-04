/*
注意使用toupper 和 isalnum两个函数
*/


class Solution {
public:
	bool isPalindrome(string s) {
		for (int i = 0, j = s.length() - 1; i <= j; )
		{
			if (!isalnum(s[i]))
			{
				++i;
				continue;
			}
			if (!isalnum(s[j]))
			{
				--j;
				continue;
			}
			if (toupper(s[i]) != toupper(s[j]))
			{
				return false;
			}
			else
			{
				++i;
				--j;
			}
		}
		return true;
	}
};