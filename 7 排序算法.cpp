//参考博客: https://blog.csdn.net/mwj327720862/article/details/80498455
#include<cstdio>
#include<iostream>
using namespace std;

/***************函数声明***************/
//打印数组
void PrintArr(int *arr, int length);
//冒泡排序 O(n^2)
void BubbleSort(int *arr, int length);
//选择排序 O(n^2)
void SelectSort(int *arr, int length);
//插入排序 O(n^2)
void InsertSort(int *arr, int length);
//快速排序 O(nlogn)
//参考博客 https://blog.csdn.net/nrsc272420199/article/details/82587933
void QuickSort(int *arr, int low, int high);
int GetIndex(int *arr, int low, int high);
/**************************************/
int main()
{
    int a[] = {4, 5, 1, 3, 6, 2};
    PrintArr(a, 6);
    QuickSort(a, 0, 5);
    PrintArr(a, 6);
}

/***************函数定义***************/
//打印数组
void PrintArr(int *arr, int length)
{
    for(int i=0;i<length;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//冒泡排序 O(n^2)
void BubbleSort(int *arr, int length)
{
    int i, j, temp;
    for(i=length-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//选择排序 O(n^2)
void SelectSort(int *arr, int length)
{
    int i, j, temp;
    for(i=0;i<length-1;i++)
    {
        int k = i;
        for(j=i+1;j<length;j++)
        {
            if(arr[j] < arr[k])
                k = j;
        }
        temp = arr[k];
        arr[k] = arr[i];
        arr[i] = temp;
    }
}

//插入排序 O(n^2)
void InsertSort(int *arr, int length)
{
    int i, j, temp;
    for(i=0;i<length-1;i++)
    {
        if(arr[i+1] < arr[i])
        {
            temp = arr[i+1];
            for(j=i;j>=0;j--)
            {
                if(arr[j] > temp)
                    arr[j+1] = arr[j];
                else break;
            }
            arr[j+1] = temp;
        }
    }
}

//快速排序 O(nlogn)
void QuickSort(int *arr, int low, int high)
{
    if(low < high)
    {
        int index = GetIndex(arr, low, high);
        QuickSort(arr, low, index-1);
        QuickSort(arr, index+1, high);
    }
}

int GetIndex(int *arr, int low, int high)
{
    int temp= arr[low];
    while(low < high)
    {
        while(arr[high] >= temp && low < high)
            high --;
        arr[low] = arr[high];
        while(arr[low] <= temp && low < high)
            low ++;
        arr[high] = arr[low];
    }
    arr[low] = temp;
    return low;
}
