//排序问题，很经典
class Solution {
public:
	static bool cmp(string a, string b) { return a + b > b + a; }//static必须有

	string largestNumber(vector<int>& nums) {
		vector<string> s;
		for (auto n : nums)
		{
			s.push_back(to_string(n));
		}
		sort(s.begin(), s.end(), cmp);
		string result;
		for (auto ss : s)
		{
			result += ss;
			//注意这里的情况，需要做一个去重处理
			/*
			Input:[0,0]
			Output:"00"
			Expected:"0"
			*/
			if (result[0] == '0' && result.size() >1)
				result.erase(0, 1);
		}

		return result;
	}
};