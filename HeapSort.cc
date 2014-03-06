#include <iostream>

inline int LeftChild(int i)
{
	return i * 2 + 1;
}

inline void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void PercDown(int a[], int n, int i)
{
	int child;
	int tmp = a[i];
	for (; LeftChild(i)<=n; i=child)
	{
		child = LeftChild(i);
		if (child < n && a[child+1] > a[child])
			++child;
		if (tmp < a[child])
			a[i] = a[child];
		else
			break;
	}
	a[i] = tmp;
}

void HeapSort(int a[], int length)
{
	int n = length - 1;
	for (int i=n/2; i>=0; --i)
		PercDown(a, n, i);

	for (int i=n; i>0; --i)
	{
		swap(a+i, a);
		PercDown(a, i-1, 0);
	}
		
}

int main()
{
	int a[10] = {12,3,6,4,1,11,26,14,27,8};
	HeapSort(a, 10);
	for (int i=0; i<10; ++i)
		std::cout << a[i] << " ";
	return 0;
}