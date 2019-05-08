class Solution {
public:
	//�ⷨ1���������
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
	//�ⷨ�����������������ŷ�����start��ʼ�������ǰ���ͱ�0��֤��������ǰ������end++�������ǰ���ͱ�0�٣�����Ҫ��ǰ���·�̽��ͣ���start--��ע������int start = gas.size() - 1, end = 0;��Ϊ�˷���start--��end++������ѭ����index��Ҫȡ��Ĳ���
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