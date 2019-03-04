void selectsort(int a[], int len)
{
	int maxI;
	for (int i = 0; i < len - 1; ++i)
	{
		maxI = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (a[j] < a[maxI])
				maxI = j;
		}
		if (maxI != i)
			swap(a[maxI], a[i]);
	}
}