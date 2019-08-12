#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 50
/*
//静态分配
typedef struct
{
    int data[MAXSIZE];
    int length;
}L;
*/

//动态分配
typedef struct
{
    int *data;
    int maxsize;
    int length;
}SqList;

//初始化表
//&是C++中的引用类型 这样对形参做任何操作可直接反映在实参上
bool InitList(SqList &L)
{
    L.data = (int *)malloc(MAXSIZE*sizeof(int));
    if(!L.data)
        exit(1);
    L.length = 0;
    L.maxsize = MAXSIZE;
    return true;
}

//插入操作
//平均时间复杂度O(n)
bool InsertList(SqList &L, int index, int value)
{
    if(index<1 || index > L.length+1) return false;
    if(L.length>=L.maxsize) //当前存储空间已满 要重新分配
    {
        int *newlist = (int *)realloc(L.data, (L.maxsize+MAXSIZE)*sizeof(int));
        if(!newlist)
            exit(2);
        L.data = newlist;
        L.maxsize += MAXSIZE;
    }

    for(int i=L.length;i>=index;i--) //必须从后往前
        L.data[i] = L.data[i-1];
    L.data[index-1] = value;
    L.length++;
    return true;

}

//删除操作
//平均时间复杂度O(n)
bool DeleteList(SqList &L, int index)
{
    if(index<1 || index > L.length) return false;

    for(int i=index-1;i<L.length-1;i++) //从前往后
        L.data[i] = L.data[i+1];
    L.length--;
    return true;
}

//查找线性表中某个元素的索引值
//平均时间复杂度O(n)
int LocateElem(SqList L, int value)
{
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i] == value)
            return i+1; //逻辑上的索引
    }
    return 0;
}

//输出所有元素值
void PrintList(SqList L)
{
    for(int i=0;i<L.length;i++)
        printf("%d ", L.data[i]);
    printf("\n");
}

//输出线性表的长度
void Length(SqList L)
{
    printf("%d\n", L.length);
}

int main()
{
    SqList L;
    InitList(L);
    InsertList(L, 1, 66);
    InsertList(L, 1, 65);
    InsertList(L, 3, 67);
    PrintList(L);
    int ans = LocateElem(L, 1);
    if(ans)
        printf("%d\n", ans);
    else
        printf("No~\n");
}
