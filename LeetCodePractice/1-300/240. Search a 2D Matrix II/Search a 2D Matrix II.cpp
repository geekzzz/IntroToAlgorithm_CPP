//从matrix的右上角开始搜索
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (m == 0)
			return false;
		int n = matrix[0].size();
		int i = 0;
		int j = n - 1;
		while (i < m && j >= 0)
		{
			if (matrix[i][j] == target)
				return true;
			if (target > matrix[i][j])
			{
				i++;
				continue;
			}
			if (target < matrix[i][j])
			{
				j--;
				continue;
			}
		}
		return false;
	}
};