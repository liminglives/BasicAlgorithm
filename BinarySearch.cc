#include <iostream>

int BinarySearch(int a[], int begin, int end, int target)
{
    if (begin > end)
        return -1;
    int mid = (begin + end) / 2;
    if (target < a[mid])
        BinarySearch(a, begin, mid-1, target);
    else if (target > a[mid])
        BinarySearch(a, mid+1, end, target);
    else
        return mid;
}

int BinarySearch2(int a[], int begin, int end, int target)
{
    int mid;
    while (begin <= end)
    {
        mid = (begin + end) / 2;
        if (target < a[mid])
            end = mid - 1;
        else if (target > a[mid])
            begin = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int a[] = {1,3,5,6,9,12,34,45,57,66};
    int ret = BinarySearch2(a, 0, 9, 45);
    std::cout << ret << std::endl;
    return 0;
}