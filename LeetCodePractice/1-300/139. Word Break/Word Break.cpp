//dp思想，dp[i + 1] 代表string s的前i个字符串能否由wordDict中的单词组成
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