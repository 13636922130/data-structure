#include<cstdio>
#include<malloc.h>

//�������нڵ����Ͷ���
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode, *LinkList;
//LNode��struct LNode�ı���
//LinkList��struct LNode *�ı���

/*
    ����ͷ�巨����������
        �βμ�һ��&��ԭ����c�ĺ�����ֵ���ݣ�
        ����һ��δ��ʼ����ָ�룬��ʵ�Ǵ���
        ָ���ֵ������ָ�������ĵ�ַ����
        ȡָ��ĵ�ַ���ݣ�����������ָ�봫��ȥ��
    ��������Ϊn ��ʱ�临�Ӷ�ΪO(n)
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

//����β�巨����������
//��Ϊ������һ��ʼ��ָ���β��ָ�� ����ʱ�临�Ӷ���O(n)
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
    ptr->next = NULL; //�ǵ��ڽ�β����NULL;
}

//����Ż�ȡԪ��
//ʱ�临�Ӷ�O(n)
LinkList GetElem(LinkList L, int index)
{
    LNode *ptr = L; //����ͷ�ڵ�
    if(index == 0)
        return L; //ֱ�ӷ���ͷ�ڵ�
    if(index < 0) return NULL;
    while(index--)
    {
        ptr = ptr->next;
        if(ptr == NULL) return ptr;
    }
    return ptr;
}

//��ֵ���ұ�ڵ�
//ʱ�临�Ӷ�O(n)
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

//����ڵ����
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

//ɾ���ڵ�
void DeleteNode(LinkList &L, int index)
{
    LNode *p = GetElem(L, index-1);
    LNode *q = p->next;
    if(q == NULL) return;
    p->next = q->next;
    free(q); //�ͷŽڵ�ռ�
}

//������
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
