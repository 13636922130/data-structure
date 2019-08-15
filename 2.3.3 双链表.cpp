#include<cstdio>
#include<malloc.h>

typedef struct Node
{
    int data;
    struct Node *next, *pre;
}Node, *LinkList;

//双链表的尾插法
void List_TailInsert(LinkList &L)
{
    Node *ptr;
    int num;
    L = (LinkList)malloc(sizeof(Node));
    L->pre = NULL;
    ptr = L;
    printf("请输入: ");
    while(scanf("%d", &num) && num != -1)
    {
        Node *n;
        n = (Node *)malloc(sizeof(Node));
        n->data = num;
        ptr->next = n;
        n->pre = ptr;
        ptr = n;
    }
    ptr->next = NULL;
}

//按序号获取元素
Node *GetElem(LinkList L, int index)
{
    Node *ptr = L;
    if(index == 0)
        return L;
    if(index < 0) return NULL;
    while(index--)
    {
        ptr = ptr->next;
        if(ptr == NULL) return ptr;
    }
    return ptr;
}

//双链表的插入
void InsertNode(LinkList &L, int index, int value)
{
    Node *ptr = GetElem(L, index-1);
    if(ptr == NULL) return;
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = value;

    n->next = ptr->next; //1
    n->pre = ptr;        //2
    ptr->next->pre = n;  //3
    ptr->next = n;       //4
    // 1和3必须要在4之前 不然指针会丢失
}

//双链表的删除
void DeleteNode(LinkList &L, int index)
{
    Node *ptr = GetElem(L, index-1);
    if(ptr == NULL) return;
    Node *q = ptr->next;
    ptr->next = q->next;
    q->next->pre = ptr;
    free(q);

}

void PrintList(LinkList L)
{
    Node *ptr = L->next;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{

}

