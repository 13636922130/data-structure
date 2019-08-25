#include<cstdio>
#include<malloc.h>
#define MAXSIZE 100

/***************函数声明***************/
//并查集的初始化
void Initial(int s[]);
//在并查集s中查找元素x的根结点
int Find(int s[], int x);
//把子集s2并到s1
void Union(int s[], int s1, int s2);
/**************************************/

int main()
{
    int UFSet[MAXSIZE];
    Initial(UFSet);
    for(int i=2;i<6;i++)
        Union(UFSet, 1, i);
    for(int i=7;i<9;i++)
        Union(UFSet, 6, i);
    for(int i=0;i<10;i++)
        printf("%d ", UFSet[i]);
}

/***************函数定义***************/
//并查集的初始化
void Initial(int s[])
{
    for(int i=0;i<MAXSIZE;i++)
        s[i] = -1; //初始化为-1
}

//在并查集s中查找元素x的根结点
int Find(int s[], int x)
{
    int ans = x;
    if(s[ans] >= 0)
        ans = s[ans]; //循环寻找根

    //路径压缩
    int r = x, temp;
    while(s[r] != -1) //把循环过程中的每个结点直接连接根节点
    {
        temp = s[r];
        s[r] = ans;
        r = s[r];
    }

    return ans;
}

//把子集s2并到s1
void Union(int s[], int s1, int s2)
{
    s1 = Find(s, s1);
    s2 = Find(s, s2);
    s[s2] = s1;
}
