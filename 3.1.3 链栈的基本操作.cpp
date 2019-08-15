#include<cstdio>
#include<malloc.h>

typedef struct LinkStack
{
    int data;
    struct LinkStack *next;
}LinkStack;

//��ջ�ĳ�ʼ��
void InitLinkStack(LinkStack *&L)
{
    L = (LinkStack *)malloc(sizeof(LinkStack));
    L->next = NULL;
}

//�ж�ջ�Ƿ��
bool StackEmpty(LinkStack *L)
{
    if(L->next == NULL) return true;
    return false;
}

/*
    ��ջ
        �����˼·�ǰ�ԭ����ͳ�ĵ������
            ͷ->1->2->3->NULL;
        ���
            NULL<-ͷ<-1<-2<-3
        ��ջ��ָ��ʼ��ָ��ջ��Ԫ��
*/
bool Push(LinkStack *&L, int value)
{
    LinkStack *node = (LinkStack *)malloc(sizeof(LinkStack));
    node->data = value;
    node->next = L;
    L = node;
    return true;
}

//��ջ
bool Pop(LinkStack *&L, int &num)
{
    if(StackEmpty(L)) return false; //ջ��
    LinkStack *ptr = L;
    num = ptr->data;
    L = ptr->next;
    free(ptr);
    return true;
}


int main()
{
    int num;
    LinkStack *L;
    InitLinkStack(L);
    Push(L, 3);
    Push(L, 2);
    Push(L, 1);
    Pop(L, num);
    printf("%d\n", num);
    Pop(L, num);
    printf("%d\n", num);
}

