#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a[5] = {1,2,3,4,5};
	vector<int> nums(a,a+5);
	for (int i  = 0;i < 2;i++)
	{
		int t = *(nums.end() - 1);
		nums.erase(nums.end()-1);
		nums.insert(nums.begin(), t);
	}
	for (auto it = nums.begin(); it != nums.end(); it++)
	{
		cout << *it << endl;
	}
	system("pause");
	return 0;
}