class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, multiset<string>> m;//ע��������õ����ݽṹ����
		vector<vector<string>> result;
		for (int i = 0; i < strs.size(); ++i)
		{
			string t = strs[i];
			sort(t.begin(), t.end());
			m[t].insert(strs[i]);//�������ĵ���Ϊkey��û�������Ϊvalue����multiset��
		}
		for (auto it = m.begin(); it != m.end(); ++it)//ע��map��α�������
		{
			vector<string> t(it->second.begin(), it->second.end());//ע��map���ȡֵ����
			result.push_back(t);
		}
		return result;
	}
};