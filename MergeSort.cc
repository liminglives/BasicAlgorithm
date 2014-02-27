#include <iostream>
using namespace std;

const int MaxOfInt = (int)((~((unsigned int)0)) >> 1);

void merge(int a[], int p, int t, int q)
{
    int len = q - p + 1;
	int len1 = t - p + 1;
	int len2 = q - t;
	int b1[len1 + 1];
	int b2[len2 + 1];

	for (int i=0; i<len1; ++i)
		b1[i] = a[p+i];
	for (int i=0; i<len2; ++i)
	    b2[i] = a[t+1+i];
	b1[len1] = MaxOfInt;
	b2[len2] = MaxOfInt;
	
	int k1,k2;
	k1=k2=0;
	for (int i=0; i<len; ++i)
	{
		if (b1[k1] < b2[k2])
		{
			a[p+i] = b1[k1];
			++k1;
		}
		else
		{
			a[p+i] = b2[k2];
			++k2;
		}
	}
}

void MergeSort(int a[], int begin, int end)
{
	if (begin >= end)
		return;
	int middle = (begin + end) / 2;
	MergeSort(a, begin, middle);
	MergeSort(a, middle+1, end);
	merge(a, begin, middle, end);
}


int main()
{
    int a[10] = {23,12,4,23,21,3,18,11,45,32};
    int aa[10] = {0,1,2,3,4,5,6,7,8,9}; 
    for (int i=0; i<10; ++i)
        std::cout << a[i] << " ";
    std::cout<<std::endl;
    MergeSort(a,0,9);
    //std::cout<<partition(a,0,9,0)<<std::endl;
    for (int i=0; i<10; ++i)
        std::cout << a[i] << " " ;
    std::cout<< std::endl;
    return 0;
	return 0;
}