class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		int colbegin = 0;
		int colend = n - 1;
		int rowbegin = 0;
		int rowend = n - 1;
		int count = 1;
		while (colbegin <= colend && rowbegin <= rowend)
		{
			for (int i = colbegin; i <= colend; ++i)
				res[rowbegin][i] = count++;
			rowbegin++;
			for (int i = rowbegin; i <= rowend; ++i)
				res[i][colend] = count++;
			colend--;
			if (rowend >= rowbegin)
				for (int i = colend; i >= colbegin; --i)
					res[rowend][i] = count++;
			rowend--;
			if (colbegin <= colend)
				for (int i = rowend; i >= rowbegin; --i)
					res[i][colbegin] = count++;
			colbegin++;
		}
		return res;
	}
};