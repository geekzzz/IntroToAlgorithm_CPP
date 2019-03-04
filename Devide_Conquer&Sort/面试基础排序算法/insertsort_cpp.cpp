void selectsort(int a[], int len)
{
	for (int i = 1; i < len; ++i)
	{
		int tmp = a[i];
		int j = i - 1;
		while (j >= 0 && tmp < a[j])
		{
			swap(a[j], a[j + 1]);
			j--;
		}
		a[j + 1] = tmp;
	}
}