//Ì°ÐÄ·¨
class Solution {
public:
	vector<int> partitionLabels(string S) {
		int start = 0;
		int end = 0;
		vector<int> res;
		vector<int> m(256, 0);
		for (int i = 0; i < S.size(); ++i)
		{
			m[S[i]] = i;
		}
		for (int i = 0; i < S.size(); ++i)
		{
			end = max(end, m[S[i]]);
			if (end == i)
			{
				res.push_back(end - start + 1);
				start = end + 1;
			}
		}
		return res;
	}
};