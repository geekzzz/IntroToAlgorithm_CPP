#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
	int a[5] = {1,1,2,2,5};
	vector<int> nums(a, a + 5);
	map<int, int> m;
	for (auto it = nums.begin(); it < nums.end(); it++)
	{
		auto s = m.find(*it);
		if (s != m.end())
		{
			m.erase(s);
		}
		else
		{
			++m[*it];
		}
	}
	cout << m.size() << "   " << m.begin()->first << m.begin()->second;
	system("pause");
	return 0;
}