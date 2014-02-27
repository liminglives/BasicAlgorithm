#include <iostream>

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int apart(int array[], int begin, int end, int pivot_position)
{
    if (begin > end)
    {
        std::cout << "error: begin > end" << std::endl;
        return -1;
    }
    if (pivot_position > end || pivot_position < begin)
    {
        std::cout << "error: pivot_position out of range" << std::endl;
        return -1;
    }
    int left = begin;
    //int key = array[pivot_position];
    int length = end - begin + 1;
    for (int i=begin; i<=end; ++i)
    {
        if (i == pivot_position)
            continue;
        if (array[i] < array[pivot_position])
        {
            if (i == left)
            {
                ++left;
                continue;
            }
            //int tmp = array[left];
            //array[left] = array[i];
            //array[i] = tmp;
            swap(array+left, array+i);
            ++left;         
        }   
    }
    swap(array+left, array+pivot_position);
    return left;
}

int partition(int a[], int begin, int end, int pivot)
{
    if (begin > end)
    {
        std::cout << "error: begin > end" << std::endl;
    }
    if (pivot > end || pivot < begin)
    {
        std::cout << "error: pivot_position out of range" << std::endl;
        return -1;
    } 
    if (pivot != end)
        swap(a+pivot, a+end);
    int left = begin;
    int right = end - 1;
    while (1)
    {
        while (a[left] < a[end])
            left++;
        while (a[right] >= a[end] && right > left)
            right--;
        if (left >= right)
            break;
        swap(a+left, a+right);
    }
    swap(a+left, a+end);
    return left;
}

void QuickSort(int array[], int begin, int end)
{
    if (begin >= end)
        return;
    //int split = apart(array, begin, end, end);
    int split = partition(array, begin, end, end);
    //for (int i=0; i<10; ++i)
    //    std::cout << array[i] << " ";
    //std::cout<<std::endl;
    QuickSort(array, begin, split-1);
    QuickSort(array, split+1, end);  
}

int main()
{
    int a[10] = {23,12,4,23,21,3,18,11,45,32};
    int aa[10] = {0,1,2,3,4,5,6,7,8,9}; 
    for (int i=0; i<10; ++i)
        std::cout << a[i] << " ";
    std::cout<<std::endl;
    QuickSort(aa,0,9);
    //std::cout<<partition(a,0,9,0)<<std::endl;
    for (int i=0; i<10; ++i)
        std::cout << aa[i] << " " ;
    std::cout<< std::endl;
    return 0;
}

