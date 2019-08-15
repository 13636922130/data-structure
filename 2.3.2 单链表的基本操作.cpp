#include<cstdio>
#include<malloc.h>

//单链表中节点类型定义
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode, *LinkList;
//LNode是struct LNode的别名
//LinkList是struct LNode *的别名

/*
    利用头插法建立单链表
        形参加一个&的原因是c的函数是值传递，
        传入一个未初始化的指针，其实是传的
        指针的值（就是指针变量存的地址）；
        取指针的地址传递，才能真正将指针传过去。
    若链表长度为n 则时间复杂度为O(n)
*/
void List_HeadInsert(LinkList &L)
{
    int num;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    while(scanf("%d", &num) && num != -1)
    {
        LNode *node;
        node = (LNode *)malloc(sizeof(LNode));
        node->data = num;
        node->next = L->next;
        L->next = node;
    }
}

//利用尾插法建立单链表
//因为设置了一个始终指向结尾的指针 所以时间复杂度是O(n)
void List_TailInsert(LinkList &L)
{
    int num;
    LNode *ptr;
    L = (LinkList)malloc(sizeof(LNode));
    ptr = L;
    while(scanf("%d", &num) && num != -1)
    {
        LNode *node;
        node = (LNode *)malloc(sizeof(LNode));
        node->data = num;
        ptr->next = node;
        ptr = node;
    }
    ptr->next = NULL; //记得在结尾加上NULL;
}

//按序号获取元素
//时间复杂度O(n)
LinkList GetElem(LinkList L, int index)
{
    LNode *ptr = L; //先在头节点
    if(index == 0)
        return L; //直接返回头节点
    if(index < 0) return NULL;
    while(index--)
    {
        ptr = ptr->next;
        if(ptr == NULL) return ptr;
    }
    return ptr;
}

//按值查找表节点
//时间复杂度O(n)
LinkList LocateElem(LinkList L, int value)
{
    LNode *ptr = L->next;
    while(ptr != NULL)
    {
        if(ptr->data == value)
            return ptr;
        else
            ptr = ptr->next;
    }
    return NULL; //
}

//插入节点操作
void InsertNode(LinkList &L, int index, int value)
{
    LNode *ptr = GetElem(L, index-1);
    if(ptr == NULL)
        return;
    LNode *node = (LNode *)malloc(sizeof(node));
    node->data = value;
    node->next = ptr->next;
    ptr->next = node;
}

//删除节点
void DeleteNode(LinkList &L, int index)
{
    LNode *p = GetElem(L, index-1);
    LNode *q = p->next;
    if(q == NULL) return;
    p->next = q->next;
    free(q); //释放节点空间
}

//链表长度
int Length(LinkList L)
{
    int len = 0;
    L = L->next;
    while(L!=NULL)
    {
        len++;
        L = L->next;
    }
    return len;
}

void PrintList(LinkList L)
{
    LNode *ptr;
    ptr = L->next;
    while(ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{

}
