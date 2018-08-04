#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int main()
{
	string s("leetcodell");
	int index = s.length();
	map<char, int> m;
	vector
	for (int i = 0; i < s.length(); ++i)
	{
		if (m.find(s[i]) == m.end())
		{
			m[s[i]] = i;
			
		}
		else
		{
			m[s[i]] = -1;
		}
	}
	cout << "          ";
	system("pause");
	return 0;
}