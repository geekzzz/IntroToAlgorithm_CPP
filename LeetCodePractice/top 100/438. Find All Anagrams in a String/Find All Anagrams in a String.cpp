//典型的substring 题目，按照substring 的模板来写，类似还有lc 76
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
				if (end - begin == p.size())//本题需要注意的点只有一个，就是当长度为p.size()的时候才能加入result，否则任意长度的子串，只要包含了p的三个字母，都会加入result
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