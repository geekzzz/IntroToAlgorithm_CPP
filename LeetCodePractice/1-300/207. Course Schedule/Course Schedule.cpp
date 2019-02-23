//���������㷨�����Ͳο���https://www.cnblogs.com/skywang12345/p/3711493.html#anchor1
//�Ľ�һ�£�ÿ�γ����е�ʱ�򣬰ѿγ�������һ����������˻�����0���ʹ������л�

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph(numCourses, unordered_set<int>());//ע�������ʼ��Ҫ����ռ䣬����ô����
		vector<int> indegree(numCourses, 0);//ע�������ʼ��Ҫ����ռ䣬����ô����
		for (int i = 0; i < prerequisites.size(); ++i)
		{
			graph[prerequisites[i].second].insert(prerequisites[i].first);
			indegree[prerequisites[i].first]++;
		}
		queue<int> q;
		for (int i = 0; i < numCourses; ++i)
		{
			if (indegree[i] == 0)
				q.push(i);
		}

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			numCourses--;
			for (int x : graph[cur])
			{
				indegree[x]--;
				if (indegree[x] == 0)
					q.push(x);
			}
		}

		return numCourses == 0;
	}
};