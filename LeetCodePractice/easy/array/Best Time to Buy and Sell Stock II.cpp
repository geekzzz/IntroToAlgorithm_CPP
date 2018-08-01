class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0;
		if (prices.size() < 2)
		{
			return 0;
		}
		for (vector<int>::iterator it = prices.begin(), it2 = prices.begin() + 1; it2 != prices.end(); it++, it2++)
		{
			int minu = *it2 - *it;
			if (minu > 0)
			{
				profit += minu;
			}
		}
		return profit;
	}
};