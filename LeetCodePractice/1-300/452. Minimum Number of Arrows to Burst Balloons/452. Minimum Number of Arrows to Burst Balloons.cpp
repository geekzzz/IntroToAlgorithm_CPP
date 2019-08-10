class Solution {
public:
	static bool cmp(const vector<int>&a, const vector<int>&b)
	{
		return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
	}

	int findMinArrowShots(vector<vector<int>>& points) {
		sort(points.begin(), points.end(), cmp);
		int arrow = INT_MIN;
		int res = 0;
		for (int i = 0; i < points.size(); ++i)
		{
			if (arrow != INT_MIN && points[i][0] <= arrow)
				continue;
			else
			{
				arrow = points[i][1];
				res++;
			}
		}
		return res;

	}
};