#include <iostream>

int MaxSubsequenceSum(int a[], int len)
{
	int sum = 0;
	int max = 0;
	for (int i=0; i<len; ++i)
	{
		sum += a[i];
		/*
		if (sum > max)
			max = sum;
			
		if (sum < 0)
			sum = 0;
		*/
		if (sum < 0)
			sum = 0;
		else if (sum > max)
			max = sum;
	}
	return max;
}

int main()
{
	int a[10] = {-1, 2, 3, 1, -2, 4, -18, 2, 1, 3,};
	std::cout << MaxSubsequenceSum(a, 10) << std::endl;
	return 0;
}