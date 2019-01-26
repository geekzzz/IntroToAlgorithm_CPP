class Solution {
public:
	class mq {
	public:
		deque<pair<int, int>> dq;
		void push(int val)
		{
			int count = 0;
			while (!dq.empty() && dq.back().first < val)//������while�ѵ�ǰС��Ҫ����ֵ�Ľڵ㶼ɾ����
			{
				count += dq.back().second + 1;//count��¼�������ͷ��λ��
				dq.pop_back();
			}
			dq.emplace_back(val, count);//�ѵ�ǰֵ����
		}
		int max()
		{
			return dq.front().first;
		}
		void pop()
		{
			if (dq.front().second > 0)//����ڵ㻹û�е�����ͷ������Ҫpop�����Ѽ�¼�������ͷ��ֵ��1����
			{
				dq.front().second--;
				return;
			}
			dq.pop_front();//�Ѿ��ڶ���ͷ��pop��
		}
	};
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> result;
		mq m;
		int i = 0;
		for (; i < k - 1; ++i)
		{
			m.push(nums[i]);
		}
		for (; i < nums.size(); ++i)
		{
			m.push(nums[i]);
			result.push_back(m.max());
			m.pop();
		}
		return result;
	}
};