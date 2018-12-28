class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string pre = "";
		if (strs.size() == 0)
			return pre;
		if (strs.size() == 1)
			return strs[0];
		int j = 0;
		bool flag = false;
		while (j < strs[0].size())
		{
			for (int i = 0; i < strs.size() - 1; ++i)
			{
				if (strs[i][j] != strs[i + 1][j])
				{
					flag = true;
				}
			}
			if (flag)
				break;
			pre += strs[0][j++];
		}
		return pre;
	}
};