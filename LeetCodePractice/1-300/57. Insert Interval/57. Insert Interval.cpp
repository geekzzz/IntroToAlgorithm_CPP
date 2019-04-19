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
		while (i < n && intervals[i][1] < newInterval[0])//��ɨ��һ�飬��ǰ���û�к�newInterval�й�ϵ�ļ���result��
			result.push_back(intervals[i++]);
		while (i < n && intervals[i][0] <= newInterval[1])//����newInterval�й�ϵ�ļ���
		{
			newInterval[0] = min(intervals[i][0], newInterval[0]);
			newInterval[1] = max(intervals[i][1], newInterval[1]);
			++i;
		}
		result.push_back(newInterval);//ѹ��result
		while (i < n)//ѹ��ʣ�µ�
			result.push_back(intervals[i++]);
		return result;
	}
};