//拓扑排序算法，解释参考：https://www.cnblogs.com/skywang12345/p/3711493.html#anchor1
//改进一下，每次出队列的时候，把课程数量减一，如果结束了还不是0，就代表了有环

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<unordered_set<int>> graph(numCourses, unordered_set<int>());//注意这里，初始化要分配空间，否则访存错误
		vector<int> indegree(numCourses, 0);//注意这里，初始化要分配空间，否则访存错误
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