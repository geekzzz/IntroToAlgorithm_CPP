class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> ans;
		for (int i = 1; i <= n; ++i)
		{
			if (i % 3 == 0)
			{
				if (i % 15 == 0)
				{
					ans.push_back("FizzBuzz");
					continue;
				}
				ans.push_back("Fizz");
				continue;
			}
			if (i % 5 == 0)
			{
				if (i % 15 == 0)
				{
					ans.push_back("FizzBuzz");
					continue;
				}
				ans.push_back("Buzz");
				continue;
			}
			ans.push_back(to_string(i));
		}
		return ans;
	}
};