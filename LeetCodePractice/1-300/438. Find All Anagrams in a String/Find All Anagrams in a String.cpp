//���͵�substring ��Ŀ������substring ��ģ����д�����ƻ���lc 76
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> m(128, 0);
		vector<int> result;
		for (int i = 0; i < p.size(); ++i)
		{
			m[p[i]]++;
		}
		int begin = 0, end = 0, counter = p.size();
		while (end < s.size())
		{
			if (m[s[end++]]-- > 0)
				counter--;
			while (counter == 0)
			{
				if (end - begin == p.size())//������Ҫע��ĵ�ֻ��һ�������ǵ�����Ϊp.size()��ʱ����ܼ���result���������ⳤ�ȵ��Ӵ���ֻҪ������p��������ĸ���������result
				{
					result.push_back(begin);
				}
				if (m[s[begin++]]++ == 0)
					counter++;
			}
		}
		return result;
	}
};