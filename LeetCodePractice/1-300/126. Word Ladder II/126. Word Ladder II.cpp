class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		//very interesting problem
		//It can be solved with standard BFS. The tricky idea is doing BFS of paths instead of words!
		//Then the queue becomes a queue of paths.


		//"visited" records all the visited nodes on this level
		//these words will never be visited again after this level 
		//and should be removed from wordList. This is guaranteed
		// by the shortest path.
		unordered_set<string> visited;
		queue<vector<string>> paths;
		vector<vector<string>> res;
		unordered_set<string> wl(wordList.begin(), wordList.end());
		if (wl.find(endWord) == wl.end())
			return res;
		paths.push({ beginWord });
		wl.insert(endWord);
		int level = 1;
		int minlevel = INT_MAX;
		while (!paths.empty())
		{
			vector<string> path = paths.front();
			paths.pop();
			//reach a new level
			if (path.size() > level)
			{
				for (auto x : visited)
					wl.erase(x);
				visited.clear();
				if (path.size() > minlevel)
					break;
				else
					level = path.size();
			}
			string last = path.back();
			for (int i = 0; i < last.size(); ++i)
			{
				string news = last;
				//find next words in wordList by changing
				//each element from 'a' to 'z'
				for (int j = 0; j < 26; ++j)
				{
					news[i] = 'a' + j;
					if (wl.find(news) != wl.end())
					{
						//next word is in wordList
						//append this word to path
						//path will be reused in the loop
						//so copy a new path
						vector<string> newpath = path;
						newpath.push_back(news);
						visited.insert(news);
						if (news == endWord)
						{
							minlevel = level;
							res.push_back(newpath);
						}
						else
							paths.push(newpath);
					}
				}
			}
		}
		return res;
	}
};