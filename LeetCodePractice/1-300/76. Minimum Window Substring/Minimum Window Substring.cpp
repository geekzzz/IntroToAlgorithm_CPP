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
			if (m[s[end++]]-- > 0)//注意这里，其实相当于先判断m[s[end]] > 0，然后是否成立，end++，m[s[end - 1]]-- ，注意end的++和m[[]]的--是同时的。
				count--;
			while (count == 0)
			{
				if (end - begin < d)
				{
					head = begin;
					d = end - begin;
				}
				if (m[s[begin++]]++ == 0)//注意这里，其实相当于先判断m[s[begin]] == 0 ，然后是否成立，begin++，m[s[begin - 1]]++ ，注意begin的++和m[[]]的++是同时的。
				{
					count++;
				}
			}
		}
		return d == INT_MAX ? "" : s.substr(head, d);
	}
};