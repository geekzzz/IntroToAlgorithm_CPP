//问题解决和lc130 Surrounded Regions 解决方法类似，从边界开始dfs
class Solution {
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& ma) {
		if (!ma.size())
			return vector<vector<int>>();
		if (!ma[0].size())
			return vector<vector<int>>();
		int m = ma.size();
		int n = ma[0].size();
		vector<vector<int>> p(m, vector<int>(n, 0));
		vector<vector<int>> a(m, vector<int>(n, 0));
		vector<vector<int>> res;
		for (int i = 0; i < m; ++i)
		{
			dfs(ma, p, i, 0, INT_MIN);
			dfs(ma, a, i, n - 1, INT_MIN);
		}
		for (int i = 0; i < n; ++i)
		{
			dfs(ma, p, 0, i, INT_MIN);
			dfs(ma, a, m - 1, i, INT_MIN);
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (p[i][j] && a[i][j])
				{
					res.push_back({ i,j });
				}
			}
		}
		return res;
	}
	void dfs(vector<vector<int>>& ma, vector<vector<int>>& pa, int i, int j, int pre)
	{
		int m = pa.size();
		int n = pa[0].size();
		if (i < 0 || i >= m || j < 0 || j >= n || ma[i][j] < pre || pa[i][j])//注意条件有pa[i][j]退出
			return;
		pa[i][j] = 1;
		dfs(ma, pa, i - 1, j, ma[i][j]);
		dfs(ma, pa, i + 1, j, ma[i][j]);
		dfs(ma, pa, i, j - 1, ma[i][j]);
		dfs(ma, pa, i, j + 1, ma[i][j]);
	}
};
