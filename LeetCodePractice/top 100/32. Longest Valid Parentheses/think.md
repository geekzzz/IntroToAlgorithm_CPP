参考： https://www.jianshu.com/p/72a4cecbf8c7
https://leetcode.com/problems/longest-valid-parentheses/discuss/14133/My-DP-O(n)-solution-without-using-stack



class Solution {
public:
	int longestValidParentheses(string s) {
		vector<int> dp(s.size(), 0);
		int max = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == ')')//如果s[i] == '(',则不合法，不考虑这种情况
			{
				if (s[i - 1] == '(')//如果s[i - 1] == '(',则只需要在dp[i - 2] 的长度上加2即可
				{
					dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;//三元运算符防止特殊情况越界
					if (dp[i] > max)
						max = dp[i];
				}

				else//s[i - 1] == ')'的情况，则需要考虑前面的字符串。
				{
					if (s[i - 1 - dp[i - 1]] == '(')// i - 1 为前面')'号的位置，dp[i - 1] 为i - 1位置的最长子串的位置，则 i - 1 - dp[i - 1]表示前面的最长子串之前的一个字符的位置，如果为'(',则可以和当前i位置的')'匹配。
					{
						/*
						
						分为两部分看，通过前面的条件已经确定这是一个合法的子串，dp[i - 1] + 2 表示当前')'匹配到的'('的子串长度，
						但是前面可能还有可能出现子串，例如()(())情况下，i = 5的时候，匹配到第2位的左括号，但是前面还有()也是合法的，所有要加上这个长度
						获取这个长度的方法为，首先计算下标：i - 1 - dp[i - 1],然后再 - 1 就得到了前面的合法子串的下标，然后就能取到长度（也有可能为0），然后相加就可以。
						同样，也有可能越界，所有用三元运算符处理越界情况。
						*/
						dp[i] = dp[i - 1] + 2 + ((i - 1 - dp[i - 1] - 1) >= 0 ? dp[i - 1 - dp[i - 1] - 1] : 0);
						if (dp[i] > max)
							max = dp[i];
					}
				}
			}
		}
		return max;
	}
};