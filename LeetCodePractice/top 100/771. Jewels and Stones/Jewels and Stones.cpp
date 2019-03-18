class Solution {
public:
	int numJewelsInStones(string J, string S) {
		unordered_map<char, int> m;
		for (int i = 0; i < S.size(); ++i)
		{
			m[S[i]]++;
		}
		int count = 0;
		for (int i = 0; i < J.size(); ++i)
		{
			count += m[J[i]];
		}
		return count;
	}
};