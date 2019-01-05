class Solution {
public:
	int strStr(string haystack, string needle) {
		int m = haystack.size(), n = needle.size();
		if (!n)
			return 0;
		vector<int> lps = processKMP(needle);
		for (int i = 0, j = 0; i < m;)
		{
			if (haystack[i] == needle[j])//��ǰ�ַ�ƥ��ɹ�
			{
				i++;
				j++;
			}
			if (j == n)//ƥ����ɣ�����
			{
				return i - j;
			}
			if ((i < m) && haystack[i] != needle[j])
			{
				if (j)//ƥ�䲻�ɹ�����j��Ϊ0��ʱ��j�ı�ָ��lps[j -1] λ��
				{
					j = lps[j - 1];
				}
				else//j Ϊ0 �����ֱ��i + 1
				{
					i++;
				}
			}
		}
		return -1;

	}
	vector<int> processKMP(string needle)//��ȡnext���飨����Ϊlps��
	{
		int n = needle.size();
		vector<int> lps(n, 0);
		for (int i = 1, len = 0; i < n;)//����lps[0]Ĭ��Ϊ0
		{
			if (needle[i] == needle[len])//�����iλ�͵�lenλ��ȣ���lps[i] = len + 1��Ȼ��i�ټ�1��
				lps[i++] = ++len;
			else if (len)//�������ȣ���Ӧ����ת����һ��ƥ���λ�ã���lps[len - 1]
				len = lps[len - 1];
			else//��len = 0 ���������.��jӦ��ָ���0�����¿�ʼ��Ȼ��i +1��
				lps[i++] = 0;
		}
		return lps;
	}
};