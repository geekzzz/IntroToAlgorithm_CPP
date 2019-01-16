class mq {
public:
	deque<pair<int, int>> dq;
	void push(int val)
	{
		int count = 0;
		while (!dq.empty() && dq.back().first < val)//这里用while把当前小于要插入值的节点都删除掉
		{
			count += dq.back().second + 1;//count记录距离队列头的位置
			dq.pop_back();
		}
		dq.emplace_back(val, count);//把当前值插入
	}
	int max()
	{
		return dq.front().first;
	}
	void pop()
	{
		if (dq.front().second > 0)//这个节点还没有到队列头，不需要pop掉，把记录距离队列头的值减1即可
		{
			dq.front().second--;
			return;
		}
		dq.pop_front();//已经在队列头，pop掉
	}
};