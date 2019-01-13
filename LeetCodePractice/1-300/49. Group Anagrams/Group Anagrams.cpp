class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, multiset<string>> m;//注意这里采用的数据结构！！
		vector<vector<string>> result;
		for (int i = 0; i < strs.size(); ++i)
		{
			string t = strs[i];
			sort(t.begin(), t.end());
			m[t].insert(strs[i]);//用排序后的单词为key，没排序的作为value插入multiset中
		}
		for (auto it = m.begin(); it != m.end(); ++it)//注意map如何遍历！！
		{
			vector<string> t(it->second.begin(), it->second.end());//注意map如何取值！！
			result.push_back(t);
		}
		return result;
	}
};