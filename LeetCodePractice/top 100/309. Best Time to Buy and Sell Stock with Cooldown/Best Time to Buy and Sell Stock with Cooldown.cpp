//dp解法，状态机表示，rest,buy,sell数组分别表示如果今天进行rest或者buy或者sell后能够得到的最大利润
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n == 0)
			return 0;
		vector<int> rest(n + 1, 0);
		vector<int> buy(n + 1, 0);
		vector<int> sell(n + 1, 0);
		buy[0] = -prices[0];
		sell[0] = INT_MIN;
		for (int i = 1; i < n; ++i)
		{
			rest[i] = max(rest[i - 1], sell[i - 1]);//rest状态能由自己或者sell状态转化
			buy[i] = max(rest[i - 1] - prices[i], buy[i - 1]);//buy状态能由rest或者buy状态转化
			sell[i] = buy[i - 1] + prices[i];//sell状态只能由buy状态转化
		}
		return max(sell[n - 1], rest[n - 1]);
	}
};