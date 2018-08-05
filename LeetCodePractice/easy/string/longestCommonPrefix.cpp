class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string pre = "";
		if (strs.size() < 2)
		{
			if (strs.size() == 0)
				return "";
			return strs[0];
		}
		for (int i = 0; i < strs.size() - 1; ++i)
		{
			int m = i == 0 ? strs[i].length() : pre.length();
			int n = strs[i + 1].length();
			int l = m < n ? m : n;
			if (l == 0)
			{
				return "";
			}
			if (i == 0)
			{
				for (int j = 0; j < l; ++j)
				{
					if (strs[i][j] == strs[i + 1][j])
					{
						pre = pre + strs[i][j];
					}
					else
					{
						break;
					}
				}
			}
			else
			{
				string t = "";
				for (int j = 0; j < l; ++j)
				{
					if (pre[j] == strs[i + 1][j])
					{
						t = t + strs[i + 1][j];
					}
					else
					{
						break;
					}
				}
				pre = t;
			}
		}
		return pre;
	}
};