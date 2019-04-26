class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		int n = T.size();
		vector<int> res(n, 0);
		stack<int> monostack;
		monostack.push(n - 1);
		for (int i = n - 2; i >= 0; --i)
		{
			while (!monostack.empty() && T[monostack.top()] <= T[i])
			{
				monostack.pop();
			}

			res[i] = monostack.empty() ? 0 : monostack.top() - i;
			monostack.push(i);
		}
		return res;
	}
};