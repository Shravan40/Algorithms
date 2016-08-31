#include <iostream>
#include <cstdio>

using namespace std;

void quicksort(int *arr, int start, int end);

int main()
{
    int arr [] = {2,6,3,9,4,3,10};
    int n = sizeof(arr) / sizeof(int);
    quicksort(arr,0,n);
    for(int i =0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quicksort(int *arr, int start, int end)
{
    if (start + 1 >= end) 
    	return;
    int pivot = arr[start];
    int smaller = start;
    for(int done = start + 1; done < end; done ++)
    {
        if (arr[done] < pivot)
        {
            swap(arr[done], arr[smaller]);
            swap(arr[done], arr[smaller + 1]);
            smaller ++;
        }
    }
    quicksort(arr, 0, smaller);
    quicksort(arr, smaller + 1, end);
}
