#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a[5] = {1,2,3,1,1};
	vector<int> prices(a,a+5);
	for (vector<int>::iterator it = prices.begin(), it2 = prices.begin() + 1; it2 != prices.end(); it++, it2++)
	{
		int profit = 0;
		int minu = *it2 - *it;
		if (minu > 0)
		{
			profit += minu;
		}
	}
	//cout << *nums.begin() << ".." << *(nums.begin()+1) << endl;
	system("pause");
	return 0;
}