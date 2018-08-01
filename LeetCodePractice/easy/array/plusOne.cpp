class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> ans;
		ans.resize(digits.size());
		int c = 1;
		for (int i = digits.size() - 1; i >= 0; --i)
		{
			if (c == 0)
			{
				ans[i] = digits[i];
			}
			int t = digits[i] + c;
			c = t / 10;
			ans[i] = t % 10;
		}
		if (c == 1)
		{
			ans.insert(ans.begin(), 1);
		}
		return ans;
	}
};