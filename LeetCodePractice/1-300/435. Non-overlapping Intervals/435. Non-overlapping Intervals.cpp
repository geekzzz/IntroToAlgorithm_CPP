class Solution {
public:
	static bool cmp(const vector<int>& a, const vector<int>& b)
	{
		return a[1] < b[1];
	}
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int n = intervals.size();
		if (!n)
			return 0;
		sort(intervals.begin(), intervals.end(), cmp);
		int preend = intervals[0][1];
		int count = 1;
		for (int i = 1; i < intervals.size(); ++i)
		{
			if (intervals[i][0] >= preend)
			{
				count++;
				preend = intervals[i][1];
			}
		}
		return n - count;
	}
};