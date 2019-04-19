class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		vector<int> res;
		if (!matrix.size())
			return res;
		if (!matrix[0].size())
			return res;
		int colbegin = 0;//分别设置4个值，用于打印
		int rowbegin = 0;
		int colend = matrix[0].size() - 1;
		int rowend = matrix.size() - 1;
		while (colbegin <= colend && rowbegin <= rowend)
		{
			for (int i = colbegin; i <= colend; ++i)
				res.push_back(matrix[rowbegin][i]);
			rowbegin++;
			for (int i = rowbegin; i <= rowend; ++i)
				res.push_back(matrix[i][colend]);
			colend--;
			if (rowbegin <= rowend)//注意这里要判断一下条件
				for (int i = colend; i >= colbegin; --i)
					res.push_back(matrix[rowend][i]);
			rowend--;
			if (colbegin <= colend)//注意这里要判断一下条件
				for (int i = rowend; i >= rowbegin; --i)
					res.push_back(matrix[i][colbegin]);
			colbegin++;
		}
		return res;
	}
};