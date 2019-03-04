//----------------堆排序O(NlgN)最大堆的实现--------------------------
/*
将最大堆的根节点和末尾交换后，可能破坏了最大堆的性质，所以要进行更新
*/
void heap_update(int a[], int i, int heap_size) {
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	int large = i;
	if (l<heap_size && a[l]>a[large])
		large = l;
	if (r<heap_size && a[r]>a[large])
		large = r;
	if (large != i) {
		swap(a[i], a[large]);
		heap_update(a, large, heap_size);
	}
}
/*
将val插入到数组a的末尾，并进行最大堆的维护
*/
void heap_insert(int a[], int val, int heap_size) {
	heap_size++;
	a[heap_size - 1] = val;
	int idx = heap_size - 1;
	while (idx>0 && a[idx / 2]<a[idx]) {
		swap(a[idx / 2], a[idx]);
		idx = idx >> 1;
	}
}
void heapSort(int a[], int len) {
	//构建最大堆
	for (int i = 0; i<len; i++)
		heap_insert(a, a[i], i);
	for (int i = len - 1; i >= 0; i--) {
		swap(a[0], a[i]);
		cout << a[i] << " ";
		heap_update(a, 0, i);  //每次heap_size减小1的
	}
}