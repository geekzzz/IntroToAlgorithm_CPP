//dp�ⷨ��״̬����ʾ��rest,buy,sell����ֱ��ʾ����������rest����buy����sell���ܹ��õ����������
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
			rest[i] = max(rest[i - 1], sell[i - 1]);//rest״̬�����Լ�����sell״̬ת��
			buy[i] = max(rest[i - 1] - prices[i], buy[i - 1]);//buy״̬����rest����buy״̬ת��
			sell[i] = buy[i - 1] + prices[i];//sell״ֻ̬����buy״̬ת��
		}
		return max(sell[n - 1], rest[n - 1]);
	}
};