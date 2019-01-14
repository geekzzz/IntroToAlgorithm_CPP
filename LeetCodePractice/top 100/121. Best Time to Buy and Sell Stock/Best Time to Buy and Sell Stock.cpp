class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int minPrice = INT_MAX, maxProfit = 0;
		for (int i = 0; i < prices.size(); ++i)
		{
			minPrice = min(minPrice, prices[i]);
			maxProfit = max(maxProfit, prices[i] - minPrice);
		}
		return maxProfit;
	}
};