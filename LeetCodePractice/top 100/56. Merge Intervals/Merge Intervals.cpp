/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
public:
	static bool cmp(const Interval &a, const Interval &b)//注意这里的写法 static，或者在sort函数中使用lambda表达式 sort(ins.begin(), ins.end(), [](Interval a, Interval b){return a.start < b.start;});
	{
		return a.start < b.start;
	}
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> result;
		if (intervals.size() == 0)
			return result;
		sort(intervals.begin(), intervals.end(), cmp);
		result.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); ++i)
		{
			if (result.back().end < intervals[i].start)
				result.push_back(intervals[i]);
			else
				result.back().end = max(result.back().end, intervals[i].end);
		}
		return result;
	}
};