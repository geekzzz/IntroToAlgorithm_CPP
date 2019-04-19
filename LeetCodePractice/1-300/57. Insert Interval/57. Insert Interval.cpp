class Solution {
public:
	/*
	static bool cmp(const vector<int>& a,const vector<int>& b)
	{
	return a[0] < b[0];
	}
	*/
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> result;
		int n = intervals.size();
		//sort(intervals.begin(),intervals.end(),cmp);
		int i = 0;
		while (i < n && intervals[i][1] < newInterval[0])//先扫描一遍，把前面的没有和newInterval有关系的加入result中
			result.push_back(intervals[i++]);
		while (i < n && intervals[i][0] <= newInterval[1])//将与newInterval有关系的加入
		{
			newInterval[0] = min(intervals[i][0], newInterval[0]);
			newInterval[1] = max(intervals[i][1], newInterval[1]);
			++i;
		}
		result.push_back(newInterval);//压入result
		while (i < n)//压入剩下的
			result.push_back(intervals[i++]);
		return result;
	}
};