//�������⣬�ܾ���
class Solution {
public:
	static bool cmp(string a, string b) { return a + b > b + a; }//static������

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
			//ע��������������Ҫ��һ��ȥ�ش���
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