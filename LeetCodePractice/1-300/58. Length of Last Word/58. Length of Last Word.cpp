//�Ӻ���ǰɨ�裬ע��ĩβ�ǿո������

class Solution {
public:
	int lengthOfLastWord(string s) {
		int n = s.size();
		if (!n)
			return 0;
		int count = 0;
		bool f = false;
		int i = s.size() - 1;
		while (i >= 0 && s[i] == ' ')//�Ȱѿո���˵�
			i--;
		for (; i >= 0; --i)
		{
			if (s[i] == ' ')
				break;
			count++;
		}
		return count;
	}
};