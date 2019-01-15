class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> m(128, 0);
		int begin = 0, end = 0, d = INT_MAX, head = 0, count = t.size();
		for (int i = 0; i < t.size(); ++i)
		{
			m[t[i]]++;
		}
		while (end < s.size())
		{
			if (m[s[end++]]-- > 0)//ע�������ʵ�൱�����ж�m[s[end]] > 0��Ȼ���Ƿ������end++��m[s[end - 1]]-- ��ע��end��++��m[[]]��--��ͬʱ�ġ�
				count--;
			while (count == 0)
			{
				if (end - begin < d)
				{
					head = begin;
					d = end - begin;
				}
				if (m[s[begin++]]++ == 0)//ע�������ʵ�൱�����ж�m[s[begin]] == 0 ��Ȼ���Ƿ������begin++��m[s[begin - 1]]++ ��ע��begin��++��m[[]]��++��ͬʱ�ġ�
				{
					count++;
				}
			}
		}
		return d == INT_MAX ? "" : s.substr(head, d);
	}
};