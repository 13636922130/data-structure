#include<cstdio>
#include<malloc.h>

int BinarySearch(int arr[], int length, int value)
{
    int left = 0, right = length - 1;
    while(left <= right)
    {
        int middle = (left + right) / 2;
        if(arr[middle] == value)
            return middle;
        else if(arr[middle] > value)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}

int main()
{
    int a[] = {7, 10, 13, 16, 19, 29, 32, 33, 37, 41, 43};
    printf("%d\n", BinarySearch(a, 11, 13));
}
