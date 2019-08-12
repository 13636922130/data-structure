#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 50
/*
//��̬����
typedef struct
{
    int data[MAXSIZE];
    int length;
}L;
*/

//��̬����
typedef struct
{
    int *data;
    int maxsize;
    int length;
}SqList;

//��ʼ����
//&��C++�е��������� �������β����κβ�����ֱ�ӷ�ӳ��ʵ����
bool InitList(SqList &L)
{
    L.data = (int *)malloc(MAXSIZE*sizeof(int));
    if(!L.data)
        exit(1);
    L.length = 0;
    L.maxsize = MAXSIZE;
    return true;
}

//�������
//ƽ��ʱ�临�Ӷ�O(n)
bool InsertList(SqList &L, int index, int value)
{
    if(index<1 || index > L.length+1) return false;
    if(L.length>=L.maxsize) //��ǰ�洢�ռ����� Ҫ���·���
    {
        int *newlist = (int *)realloc(L.data, (L.maxsize+MAXSIZE)*sizeof(int));
        if(!newlist)
            exit(2);
        L.data = newlist;
        L.maxsize += MAXSIZE;
    }

    for(int i=L.length;i>=index;i--) //����Ӻ���ǰ
        L.data[i] = L.data[i-1];
    L.data[index-1] = value;
    L.length++;
    return true;

}

//ɾ������
//ƽ��ʱ�临�Ӷ�O(n)
bool DeleteList(SqList &L, int index)
{
    if(index<1 || index > L.length) return false;

    for(int i=index-1;i<L.length-1;i++) //��ǰ����
        L.data[i] = L.data[i+1];
    L.length--;
    return true;
}

//�������Ա���ĳ��Ԫ�ص�����ֵ
//ƽ��ʱ�临�Ӷ�O(n)
int LocateElem(SqList L, int value)
{
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i] == value)
            return i+1; //�߼��ϵ�����
    }
    return 0;
}

//�������Ԫ��ֵ
void PrintList(SqList L)
{
    for(int i=0;i<L.length;i++)
        printf("%d ", L.data[i]);
    printf("\n");
}

//������Ա�ĳ���
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
