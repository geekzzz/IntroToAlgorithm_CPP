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
//#include "a.h"
#include <istream>
#include <fstream>
#include <unordered_map> 
using namespace std;

//class Singlinton
//{
//private:
//	Singlinton();
//	~Singlinton();
//	Singlinton(const Singlinton&);
//	Singlinton& operator=(const Singlinton&);
//public:
//	static Singlinton& getinstance()
//	{
//		static Singlinton instance;
//		return instance;
//	}
//	
//}



//void bubblesort(vector<int>& a)
//{
//	int n = a.size();
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n - i - 1; ++j)
//			if (a[j] > a[j + 1])
//				swap(a[j], a[j + 1]);
//	}
//}


void mergearray(vector<int> & v, int start, int mid, int end)
{
	vector<int> t;
	int i = start;
	int j = mid + 1;
	while (i <= mid && j <= end)
	{
		if (v[i] <= v[j])
		{
			t.push_back(v[i]);
			i++;
		}
		else
		{
			t.push_back(v[j]);
			j++;
		}
	}
	while (i <= mid)
	{
		t.push_back(v[i]);
		i++;
	}

	while (j <= end)
	{
		t.push_back(v[j]);
		j++;
	}

	for (int i = 0; i < end - start + 1; ++i)
		v[start + i] = t[i];
}


void mergesort(vector<int> & v, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergesort(v, start, mid);
		mergesort(v, mid + 1, end);
		mergearray(v, start, mid, end);
	}
}


int main()
{
	vector<int> v{ 10,11,3,2,5,6,7,1,9,8,14,13,12 };
	mergesort(v, 0, v.size() - 1);
	for (auto x : v)
		cout << x << " : ";
	system("pause");
	return 0;
}