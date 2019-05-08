class Solution {
public:
	//解法1，暴力求解
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		for (int i = 0; i < n; ++i)
		{
			for (int nowgas = gas[i], j = i;;)
			{
				nowgas -= cost[j];
				if (nowgas < 0)
					break;
				int t = ++j;
				t %= n;
				j = t;
				if (j == i)
					return i;
				nowgas += gas[j];
			}
		}
		return -1;
	}
	//解法二，类似于中心扩张法，从start开始，如果当前的油比0多证明可以往前开，则end++，如果当前的油比0少，则需要从前面的路程借油，则start--，注意这里int start = gas.size() - 1, end = 0;是为了方便start--和end++，避免循环后index需要取余的操作
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int start = gas.size() - 1, end = 0;
		int nowgas = gas[start] - cost[start];
		while (end < start)
		{
			if (nowgas < 0)
			{
				start--;
				nowgas = nowgas + gas[start] - cost[start];
			}
			else
			{
				nowgas = nowgas + gas[end] - cost[end];
				end++;
			}
		}
		return nowgas >= 0 ? start : -1;
	}
};