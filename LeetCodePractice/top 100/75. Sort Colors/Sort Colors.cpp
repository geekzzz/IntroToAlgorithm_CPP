// one pass in place solution
void sortColors(int A[], int n) {
	int j = 0, k = n - 1;
	for (int i = 0; i <= k; i++) //注意这里终止条件为i <= k
	{
		if (A[i] == 0)
			swap(A[i], A[j++]);//注意这里i不变
		else if (A[i] == 2)
			swap(A[i--], A[k--]);//注意这里i--
	}
}

// two pass O(m+n) space
void sortColors(int A[], int n) {
	int num0 = 0, num1 = 0, num2 = 0;

	for (int i = 0; i < n; i++) {
		if (A[i] == 0) ++num0;
		else if (A[i] == 1) ++num1;
		else if (A[i] == 2) ++num2;
	}

	for (int i = 0; i < num0; ++i) A[i] = 0;
	for (int i = 0; i < num1; ++i) A[num0 + i] = 1;
	for (int i = 0; i < num2; ++i) A[num0 + num1 + i] = 2;
}

// one pass in place solution
void sortColors(int A[], int n) {
	int n0 = -1, n1 = -1, n2 = -1;
	for (int i = 0; i < n; ++i) {
		if (A[i] == 0)
		{
			A[++n2] = 2; A[++n1] = 1; A[++n0] = 0;
		}
		else if (A[i] == 1)
		{
			A[++n2] = 2; A[++n1] = 1;
		}
		else if (A[i] == 2)
		{
			A[++n2] = 2;
		}
	}
}

// one pass in place solution
void sortColors(int A[], int n) {
	int j = 0, k = n - 1;
	for (int i = 0; i <= k; ++i) {
		if (A[i] == 0 && i != j)
			swap(A[i--], A[j++]);
		else if (A[i] == 2 && i != k)
			swap(A[i--], A[k--]);
	}
}

