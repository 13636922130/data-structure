#include<cstdio>
#include<malloc.h>
#define MAXSIZE 50

typedef struct
{
    int data[MAXSIZE];
    int front, rear;
}Queue;

//���еĳ�ʼ��
void InitQueue(Queue &q)
{
    q.front = q.rear = 0;
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue q)
{
    if(q.front == q.rear) return true;
    return false;
}

//�ж϶����Ƿ�Ϊ��
bool QueueFull(Queue q)
{
    if(q.rear == MAXSIZE) return true;
    return false;
}

//������
bool EnQueue(Queue &q, int num)
{
    if(QueueFull(q)) return false;
    q.data[q.rear++] = num;
    return true;
}

//������
bool DeQueue(Queue &q, int &num)
{
    if(QueueEmpty(q)) return false;
    num = q.data[q.front++];
    return true;
}

//��ȡ��ͷԪ��
bool GetHead(Queue q, int &num)
{
    if(QueueEmpty(q)) return false;
    num = q.data[q.front];
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
    DeQueue(q, num);
    printf("%d\n", num);
    GetHead(q, num);
    printf("%d\n", num);
    DeQueue(q, num);
    printf("%d\n", num);
    DeQueue(q, num);
    printf("%d\n", num);

}
