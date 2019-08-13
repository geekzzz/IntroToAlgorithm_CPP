class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int n = M.size();
		int count = 0;
		vector<bool> find(n, false);
		for (int i = 0; i < M.size(); ++i)
		{
			if (!find[i])
			{
				count++;
				dfs(i, M, find);
			}
		}
		return count;
	}
	void dfs(int i, vector<vector<int>>& M, vector<bool>& find)
	{
		find[i] = true;
		for (int j = 0; j < M.size(); ++j)
		{
			if (M[i][j] == 1 && !find[j])
				dfs(j, M, find);
		}
	}
};