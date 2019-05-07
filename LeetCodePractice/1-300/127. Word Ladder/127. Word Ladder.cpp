class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		int count = 1;
		unordered_set<string> set(wordList.begin(), wordList.end());
		queue<string> q;
		q.push(beginWord);
		while (!q.empty())
		{
			int xx = q.size();//ע������Ҫ����д����Ϊq��size�Ǳ仯�ģ�ֱ��дfor (int x = 0; x < q.size(); ++x) �������⣬bfsд��ʱ��Ҫע��
			for (int x = 0; x < xx; ++x)
			{
				string t = q.front();
				q.pop();
				if (t == endWord)
					return count;
				set.erase(t);
				for (int i = 0; i < t.size(); ++i)
				{
					char c = t[i];
					for (int j = 0; j < 26; ++j)
					{
						t[i] = 'a' + j;
						if (set.find(t) != set.end())
							q.push(t);
					}
					t[i] = c;
				}
			}
			count++;
		}
		return 0;
	}
};