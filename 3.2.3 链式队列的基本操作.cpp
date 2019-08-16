#include<cstdio>
#include<malloc.h>

//��ʽ���нڵ�
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
}LinkNode;

//��ʽ����
typedef struct
{
    LinkNode *front, *rear;
}Queue;

/*
    ��ʽ���д�ŵĽṹ���£�

    ͷ->1->2->3->4->NULL
    ��           ��
    |            |
    front       rear

    frontʼ����ͷ�ڵ�,ͨ����ȡ�¸��ڵ��ֵ������

    ����һֱ������push 1, 2, 3 ,4�����
*/


//��ʼ��
void InitQueue(Queue &q)
{
    q.front = (LinkNode *)malloc(sizeof(LinkNode));
    q.rear = q.front;
    q.front->next = NULL; //
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue q)
{
    if(q.front == q.rear) return true;
    return false;
}

//���
//����β�巨
void EnQueue(Queue &q, int num)
{
    LinkNode *ptr = (LinkNode *)malloc(sizeof(LinkNode));
    ptr->data = num;
    ptr->next = q.rear->next; //�ȼ���ptr->next = NULL
    q.rear->next = ptr;
    q.rear = ptr;
}

//����
bool DeQueue(Queue &q, int &num)
{
    if(QueueEmpty(q)) return false;
    LinkNode *ptr = q.front->next;
    num = ptr->data;
    q.front->next = ptr->next;

    if(q.rear == ptr)      //�����г���ͷ�ڵ������Ψһ�ڵ�ʱ
        q.rear = q.front;  //��ֹ������ڵ��ͷź�rearָ��ա��޷�
                           //�ж϶���Ϊ�յ����

    free(ptr); //��Ҫ�Ѷ�ͷ�ͷ�
    return true;
}

int main()
{
    int num;
    Queue q;
    InitQueue(q);
    EnQueue(q, 1);
    EnQueue(q, 2);
    EnQueue(q, 3);
    if(!DeQueue(q, num)) printf("Queue Empty!\n");
    printf("%d\n", num);
    if(!DeQueue(q, num)) printf("Queue Empty!\n");
    printf("%d\n", num);
    if(!DeQueue(q, num)) printf("Queue Empty!\n");
    printf("%d\n", num);
    if(!DeQueue(q, num)) printf("Queue Empty!\n");
    printf("%d\n", num);
}
