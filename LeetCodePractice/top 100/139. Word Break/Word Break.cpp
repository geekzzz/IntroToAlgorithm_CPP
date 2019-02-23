//dp˼�룬dp[i + 1] ����string s��ǰi���ַ����ܷ���wordDict�еĵ������
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		unordered_set<string> d(wordDict.begin(), wordDict.end());
		for (int i = 0; i < s.size(); ++i)
		{
			for (int j = i; j >= 0; --j)
			{
				if (dp[j])
				{
					string t = s.substr(j, i - j + 1);
					if (d.find(t) != d.end())
					{
						dp[i + 1] = true;
					}
				}
			}
		}
		return dp[s.size()];
	}

}
};