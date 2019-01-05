class Solution {
public:
	int strStr(string haystack, string needle) {
		int m = haystack.size(), n = needle.size();
		if (!n)
			return 0;
		vector<int> lps = processKMP(needle);
		for (int i = 0, j = 0; i < m;)
		{
			if (haystack[i] == needle[j])//当前字符匹配成功
			{
				i++;
				j++;
			}
			if (j == n)//匹配完成，返回
			{
				return i - j;
			}
			if ((i < m) && haystack[i] != needle[j])
			{
				if (j)//匹配不成功，当j不为0的时候，j改变指向到lps[j -1] 位置
				{
					j = lps[j - 1];
				}
				else//j 为0 情况，直接i + 1
				{
					i++;
				}
			}
		}
		return -1;

	}
	vector<int> processKMP(string needle)//获取next数组（这里为lps）
	{
		int n = needle.size();
		vector<int> lps(n, 0);
		for (int i = 1, len = 0; i < n;)//这里lps[0]默认为0
		{
			if (needle[i] == needle[len])//如果第i位和第len位相等，则lps[i] = len + 1，然后i再加1；
				lps[i++] = ++len;
			else if (len)//如果不相等，则应该跳转到上一次匹配的位置，即lps[len - 1]
				len = lps[len - 1];
			else//当len = 0 的特殊情况.则j应该指向回0，重新开始。然后i +1；
				lps[i++] = 0;
		}
		return lps;
	}
};