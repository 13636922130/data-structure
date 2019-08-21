#include<cstdio>
#include<malloc.h>

typedef struct LinkStack
{
    int data;
    struct LinkStack *next;
}LinkStack;

//链栈的初始化
void InitStack(LinkStack *&L)
{
    L = (LinkStack *)malloc(sizeof(LinkStack));
    L->next = NULL;
}

//判断栈是否空
bool StackEmpty(LinkStack *L)
{
    if(L->next == NULL) return true;
    return false;
}

/*
    进栈
        这里的思路是把原来传统的单链表的
            头->1->2->3->NULL;
        变成
            NULL<-头<-1<-2<-3
        链栈的指针始终指向栈顶元素
*/
bool Push(LinkStack *&L, int value)
{
    LinkStack *node = (LinkStack *)malloc(sizeof(LinkStack));
    node->data = value;
    node->next = L;
    L = node;
    return true;
}

//出栈
bool Pop(LinkStack *&L, int &num)
{
    if(StackEmpty(L)) return false; //栈空
    LinkStack *ptr = L;
    num = ptr->data;
    L = ptr->next;
    free(ptr);
    return true;
}

//获取栈顶元素
bool GetTop(LinkStack *L, int &num)
{
    if(StackEmpty(L)) return false;
    num = L->data;
    return true;
}

int main()
{
    int num;
    LinkStack *L;
    InitStack(L);
    Push(L, 3);
    Push(L, 2);
    Push(L, 1);
    Pop(L, num);
    printf("%d\n", num);
    GetTop(L, num);
    printf("%d\n", num);
    GetTop(L, num);
    printf("%d\n", num);
    Pop(L, num);
    printf("%d\n", num);
    Pop(L, num);
    printf("%d\n", num);

}

