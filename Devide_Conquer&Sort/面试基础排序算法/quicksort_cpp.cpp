#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<ctype.h>
#include<math.h>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>
#include<algorithm>
#include<time.h>
#include<deque>
#include <unordered_set>
#include <functional>
#include <Windows.h>
#include <istream>
#include <fstream>
#include <unordered_map> 
using namespace std;

void quicksort(vector<int>& a, int left, int right)
{
	int pivot = a[left];
	int l = left, r = right;
	if (l < r)
	{
		while (l < r)
		{
			while (l < r &&  a[l] > pivot)
				l++;
			if (l < r)
			{
				a[r] = a[l];
				r--;
			}
			while (l < r && a[r] <= pivot)
				r--;
			if (l < r)
			{
				a[l] = a[r];
				l++;
			}
		}
		a[l] = pivot;
		quicksort(a, left, l - 1);
		quicksort(a, l + 1, right);
	}
}



int main()
{
	vector<int> v{ 10,11,3,2,5,6,7,1,9,8,14,13,12 };
	//bubblesort(v);
	quicksort(v, 0, v.size() - 1);
	for (auto x : v)
		cout << x << " : ";
	system("pause");
	return 0;
}